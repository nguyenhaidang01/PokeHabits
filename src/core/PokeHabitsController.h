#pragma once

#include <QMap>
#include <QDate>

#include "UiController.h"

class CalendarModel;

class PokeHabitsController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(CalendarModel* calendarModel READ calendarModel CONSTANT)
	Q_PROPERTY(UiController* uiController READ uiController CONSTANT)

public:
	static PokeHabitsController* getInstance();

	CalendarModel* calendarModel();
	UiController* uiController();
public slots:

signals:

private:
	explicit PokeHabitsController(QObject *parent = nullptr);

	QVector<QDate> createCalendarListForYear(int year);

	CalendarModel* m_calendarModel;
	UiController* m_uiController;
};
