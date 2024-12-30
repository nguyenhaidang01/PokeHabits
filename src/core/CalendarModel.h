/******************************************************************************
**
** File      CalendarModel.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <QAbstractListModel>
#include <QDate>

using CalendarListPtr = std::shared_ptr<QVector<QDate>>;

class CalendarModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int currentDateIndex READ currentDateIndex CONSTANT)
	Q_PROPERTY(QString currentDateStr READ currentDateStr CONSTANT)
	Q_PROPERTY(QString selectedDateStr READ selectedDateStr NOTIFY selectedDateChanged FINAL)

public:
	explicit CalendarModel(CalendarListPtr calendarList, QObject *parent = nullptr);

	enum {
		DayOfWeekRole = Qt::UserRole,
		DayRole,
		MonthNameRole,
		MonthNumberRole,
		YearRole,
		IsCurrentDateRole,
		IsInCurrentMonthRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual QHash<int, QByteArray> roleNames() const override;

	CalendarListPtr list() const;
	void setList(CalendarListPtr list);

	int currentDateIndex() const;
	QString currentDateStr() const;

	QDate selectedDate() const;
	QString selectedDateStr() const;

public slots:
	void setSelectedDate(int year, int month, int day);

signals:
	void selectedDateChanged(QDate date);

private:
	int m_currentDateIndex;
	QDate m_selectedDate;

	CalendarListPtr m_List;
};
