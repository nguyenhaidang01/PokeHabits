#pragma once

#include <QMap>
#include <QDate>

#include "UiService.h"

class CalendarModel;

class PokeHabitsController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(CalendarModel* calendarModel READ calendarModel CONSTANT)
	Q_PROPERTY(UiService* uiService READ uiService CONSTANT)

public:
	static PokeHabitsController* getInstance();

	CalendarModel* calendarModel();
	UiService* uiService();
public slots:

signals:

private:
	explicit PokeHabitsController(QObject *parent = nullptr);

	QVector<QDate> createCalendarListForYear(int year);

	CalendarModel* m_calendarModel;
	UiService* m_uiService;
};
