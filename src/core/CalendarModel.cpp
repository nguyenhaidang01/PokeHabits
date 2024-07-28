#include "CalendarModel.h"
#include "CalendarList.h"

CalendarModel::CalendarModel(std::shared_ptr<CalendarList> calendarList, QDate currentDate, QObject *parent)
	: QAbstractListModel{parent}
	, m_calendarList{calendarList}
	, m_currentDate{currentDate}
	, m_selectedDate{currentDate}
{
}

int CalendarModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_calendarList)
		return 0;

	return m_calendarList->items()->size();
}

QVariant CalendarModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_calendarList)
		return QVariant();

	const QDate item = m_calendarList->items()->at(index.row());
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

std::shared_ptr<CalendarList> CalendarModel::calendarList() const
{
	return m_calendarList;
}

void CalendarModel::setCalendarList(std::shared_ptr<CalendarList> list)
{
	beginResetModel();

	if (m_calendarList) {
		m_calendarList->disconnect(this);
	}

	m_calendarList = list;

	if (m_calendarList) {
		connect(m_calendarList.get(), &CalendarList::preDateItemAppended, this, [=]() {
			const int index = m_calendarList->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_calendarList.get(), &CalendarList::postDateItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_calendarList.get(), &CalendarList::preDateItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_calendarList.get(), &CalendarList::postDateItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}

int CalendarModel::currentDateIndex()
{
	return m_calendarList->items()->indexOf(m_currentDate);
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
