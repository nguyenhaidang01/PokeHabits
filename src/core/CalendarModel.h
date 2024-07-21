#pragma once

#include "CalendarList.h"
#include <QAbstractListModel>

Q_MOC_INCLUDE("CalendarList.h")

class CalendarModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(CalendarList *calendarList READ calendarList WRITE setCalendarList)

public:
	explicit CalendarModel(QObject *parent = nullptr);
	explicit CalendarModel(CalendarList *calendarList, QObject *parent = nullptr);

	enum {
		DayOfWeekRole = Qt::UserRole,
		DayRole,
		MonthRole,
		YearRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	// bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;

	virtual QHash<int, QByteArray> roleNames() const override;

	CalendarList* calendarList() const;
	void setCalendarList(CalendarList* list);

private:
	CalendarList* m_calendarList;
};
