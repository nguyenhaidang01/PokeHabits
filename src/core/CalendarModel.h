#pragma once

#include <QAbstractListModel>
#include "CalendarList.h"

using CalendarListPtr = std::shared_ptr<CalendarList>;

class CalendarModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int currentDateIndex READ currentDateIndex CONSTANT)
	Q_PROPERTY(QString selectedMonth READ selectedMonth NOTIFY selectedDateChanged FINAL)
	Q_PROPERTY(int selectedYear READ selectedYear NOTIFY selectedDateChanged FINAL)

public:
	explicit CalendarModel(CalendarListPtr calendarList, QDate currentDate, QObject *parent = nullptr);

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

	CalendarListPtr list() const;
	void setList(CalendarListPtr list);

	int currentDateIndex();

	QDate selectedDate();
	void setSelectedDate(QDate date);

	QString selectedMonth();
	int selectedYear();

signals:
	void selectedDateChanged();

private:
	CalendarListPtr m_List;

	QDate m_currentDate;
	QDate m_selectedDate;
};
