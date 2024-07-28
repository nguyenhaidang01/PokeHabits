#pragma once

#include "CalendarList.h"
#include <QAbstractListModel>

Q_MOC_INCLUDE("CalendarList.h")

class CalendarModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int currentDateIndex READ currentDateIndex CONSTANT)
	Q_PROPERTY(QString selectedMonth READ selectedMonth NOTIFY selectedDateChanged FINAL)
	Q_PROPERTY(int selectedYear READ selectedYear NOTIFY selectedDateChanged FINAL)

public:
	explicit CalendarModel(std::shared_ptr<CalendarList> calendarList, QDate currentDate, QObject *parent = nullptr);

	enum {
		DayOfWeekRole = Qt::UserRole,
		DayRole,
		MonthRole,
		NumericMonthRole,
		YearRole,
		IsSundayRole,
		IsCurrentDateRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual QHash<int, QByteArray> roleNames() const override;

	std::shared_ptr<CalendarList> calendarList() const;
	void setCalendarList(std::shared_ptr<CalendarList> list);

	int currentDateIndex();

	QDate selectedDate();
	void setSelectedDate(QDate date);

	QString selectedMonth();
	int selectedYear();

signals:
	void selectedDateChanged();

private:
	std::shared_ptr<CalendarList> m_calendarList;
	QDate m_currentDate;
	QDate m_selectedDate;
};
