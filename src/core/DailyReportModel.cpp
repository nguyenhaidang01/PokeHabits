#include "Pokemon.h"
#include "DailyReportList.h"
#include "DailyReportModel.h"

DailyReportModel::DailyReportModel(QObject *parent)
    : QAbstractListModel{parent}
    , m_dailyReportList{nullptr}
{
}

DailyReportModel::DailyReportModel(std::shared_ptr<DailyReportList> dailyReportList, QObject *parent)
    : QAbstractListModel{parent}
    , m_dailyReportList{dailyReportList}
{
	QObject::connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemAppended, this, &DailyReportModel::countChanged);
	QObject::connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemAppended, this, &DailyReportModel::countChanged);
}

int DailyReportModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_dailyReportList)
		return 0;

	return m_dailyReportList->items()->size();
}

QVariant DailyReportModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_dailyReportList)
		return QVariant();

	const std::shared_ptr<PokeHabit> item = m_dailyReportList->items()->at(index.row());
	switch (role) {
	case HabitNameRole:
		return QVariant(item->habitName);
	case ImageRole:
		return QVariant(item->image);
	case ExpRole:
		return QVariant(item->exp);
	case DoneRole:
		return QVariant(item->done);
	}

	return QVariant();
}

bool DailyReportModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!m_dailyReportList)
		return false;

	std::shared_ptr<PokeHabit> item = m_dailyReportList->items()->at(index.row());
	switch (role) {
	case HabitNameRole:
		item->habitName = value.toString();
		break;
	case ImageRole:
		item->image = value.toString();
		break;
	case ExpRole:
		item->exp = value.toInt();
		break;
	case DoneRole:
		item->done = value.toBool();
		break;
	}

	if (m_dailyReportList->setDailyReporItemAt(index.row(), item)) {
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
}

Qt::ItemFlags DailyReportModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	return Qt::ItemIsEditable;
}

QHash<int, QByteArray> DailyReportModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[HabitNameRole] = "habitName";
	names[ImageRole] = "image";
	names[ExpRole] = "exp";
	names[DoneRole] = "done";

	return names;
}

std::shared_ptr<DailyReportList> DailyReportModel::dailyReportList() const
{
	return m_dailyReportList;
}

void DailyReportModel::setDailyReportList(std::shared_ptr<DailyReportList> list)
{
	beginResetModel();

	if (m_dailyReportList) {
		m_dailyReportList->disconnect(this);
	}

	m_dailyReportList = list;

	if (m_dailyReportList) {
		connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemAppended, this, [=]() {
			const int index = m_dailyReportList->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}

int DailyReportModel::count()
{
	return m_dailyReportList->items()->size();
}
