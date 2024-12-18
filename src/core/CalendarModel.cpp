/******************************************************************************
**
** File      CalendarModel.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "CalendarModel.h"

CalendarModel::CalendarModel(CalendarListPtr calendarList, QObject *parent)
	: QAbstractListModel(parent)
	, m_List{ calendarList }
	, m_selectedDate{ QDate::currentDate() }
{
}

int CalendarModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_List)
		return 0;

	return m_List->size();
}

QVariant CalendarModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_List)
		return QVariant();

	const QDate &item = m_List->at(index.row());
	switch (role) {
	case DayOfWeekRole:
		return QVariant(item.toString("ddd").toUpper());
	case DayRole:
		return QVariant(item.toString("d"));
	case MonthNameRole:
		return QVariant(item.toString("MMMM"));
	case MonthNumberRole:
		return QVariant(item.month());
	case YearRole:
		return QVariant(item.toString("yyyy"));
	case IsCurrentDateRole:
		return QVariant(item == QDate::currentDate());
	case IsInCurrentMonthRole:
		return QVariant(item.month() == QDate::currentDate().month());
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
	names[MonthNameRole] = "monthName";
	names[MonthNumberRole] = "monthNumber";
	names[YearRole] = "year";
	names[IsCurrentDateRole] = "isCurrentDate";
	names[IsInCurrentMonthRole] = "isInCurrentMonth";

	return names;
}

CalendarListPtr CalendarModel::list() const
{
	return m_List;
}

void CalendarModel::setList(CalendarListPtr list)
{
	beginResetModel();
	m_List = list;
	endResetModel();
}

int CalendarModel::currentDateIndex() const
{
	return m_List->indexOf(QDate::currentDate());
}

QString CalendarModel::selectedDateStr() const
{
	return m_selectedDate.toString("MMMM d, yyyy");
}

QDate CalendarModel::selectedDate() const
{
	return m_selectedDate;
}

void CalendarModel::setSelectedDate(QDate newSelectedDate)
{
	if (newSelectedDate == m_selectedDate) {
		return;
	}
	m_selectedDate = newSelectedDate;
}
