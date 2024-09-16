#pragma once

#include <QMap>
#include <QDate>

#include "CalendarModel.h"
#include "DailyReportModel.h"
#include "PokeApiManager.h"
#include "DatabaseManager.h"

using QMapDateDailyReportModelPtr = std::shared_ptr<QMap<QDate, DailyReportModel*>>;
using QMapYearCalendarModelPtr = std::shared_ptr<QMap<int, CalendarModel*>>;

class PokeHabitsApp : public QObject
{
	Q_OBJECT
	Q_PROPERTY(DailyReportModel* dailyReportModel READ dailyReportModel NOTIFY dailyReportModelChanged FINAL)
	Q_PROPERTY(CalendarModel* calendarModel READ calendarModel NOTIFY calendarModelChanged FINAL)

public:
	static PokeHabitsApp* getInstance();

	DailyReportModel* dailyReportModel();
	CalendarModel* calendarModel();

public slots:
	PokemonModel* pokemonModel();

	void setSelectedDate(int day, int month, int year);
	void addPokeHabit(QString habitName);

signals:
	void selectedDateChanged();
	void dailyReportModelChanged();
	void calendarModelChanged();

private:
	explicit PokeHabitsApp(QObject *parent = nullptr);

	CalendarModel* createCalendarModel(QDate date);
	void createDailyReportModelsFromDatabase();
	void createCurrentDateReport();

	QMapYearCalendarModelPtr m_allCalendarModel;
	QMapDateDailyReportModelPtr m_allDailyReportModel;

	PokeApiManager* m_pokeApiManager;
	DatabaseManager* m_databaseManager;

	QDate m_currentDate;
	QDate m_selectedDate;
};
