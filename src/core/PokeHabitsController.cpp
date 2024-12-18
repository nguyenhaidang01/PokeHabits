#include "PokeHabitsController.h"

#include "CalendarModel.h"

#define USERNAME "DangNH"
#define PASSWORD "CR7GOAT"

static PokeHabitsController* instance = nullptr;

PokeHabitsController* PokeHabitsController::getInstance()
{
	if (!instance) {
		instance = new PokeHabitsController();
	}
	return instance;
}

PokeHabitsController::PokeHabitsController(QObject *parent)
	: QObject(parent)
    , m_uiController{ new UiController() }
{
	const auto &dates = createCalendarListForYear(QDate::currentDate().year());
	m_calendarModel = new CalendarModel(std::make_shared<QVector<QDate>>(dates));
}

CalendarModel* PokeHabitsController::calendarModel()
{
	return m_calendarModel;
}

UiController* PokeHabitsController::uiController()
{
	return m_uiController;
}

QVector<QDate> PokeHabitsController::createCalendarListForYear(int year)
{
	QVector<QDate> dates;

	QDate startDate(year, 1, 1);
	QDate endDate(year, 12, 31);

	for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
		dates.append(date);
	}

	return dates;
}
