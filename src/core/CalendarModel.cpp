#include "CalendarModel.h"

CalendarModel::CalendarModel(CalendarListPtr calendarList, QDate currentDate, QObject *parent)
	: QAbstractListModel(parent)
	, m_List{ calendarList }
	, m_currentDate{ currentDate }
	, m_selectedDate{ currentDate }
{
}

int CalendarModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_List)
		return 0;

	return m_List->items()->size();
}

QVariant CalendarModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_List)
		return QVariant();

	const QDate item = m_List->items()->at(index.row());
	switch (role) {
	case DayOfWeekRole:
		return QVariant(item.toString("ddd").toUpper());
	case DayRole:
		return QVariant(item.toString("d"));
	case MonthRole:
		return QVariant(item.toString("MMMM"));
	case NumericMonthRole:
		return QVariant(item.month());
	case YearRole:
		return QVariant(item.toString("yyyy"));
	case IsSundayRole:
		return QVariant(item.dayOfWeek() == 7);
	case IsCurrentDateRole:
		return QVariant(item == m_currentDate);
	}

	return QVariant();
}

Qt::ItemFlags CalendarModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CalendarModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[DayOfWeekRole] = "dayOfWeek";
	names[DayRole] = "day";
	names[MonthRole] = "month";
	names[NumericMonthRole] = "numericMonth";
	names[YearRole] = "year";
	names[IsSundayRole] = "isSunday";
	names[IsCurrentDateRole] = "isCurrentDate";

	return names;
}

CalendarListPtr CalendarModel::list() const
{
	return m_List;
}

void CalendarModel::setList(CalendarListPtr list)
{
	beginResetModel();

	if (m_List) {
		m_List->disconnect(this);
	}

	m_List = list;

	if (m_List) {
		connect(m_List.get(), &CalendarList::preItemAppended, this, [=]() {
			const int index = m_List->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_List.get(), &CalendarList::postItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_List.get(), &CalendarList::preItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_List.get(), &CalendarList::postItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}

int CalendarModel::currentDateIndex()
{
	return m_List->items()->indexOf(m_currentDate);
}

QDate CalendarModel::selectedDate()
{
	return m_selectedDate;
}

void CalendarModel::setSelectedDate(QDate date)
{
	m_selectedDate = date;
	emit selectedDateChanged();
}

QString CalendarModel::selectedMonth()
{
	return m_selectedDate.toString("MMMM").toUpper();
}

int CalendarModel::selectedYear()
{
	return m_selectedDate.year();
}
