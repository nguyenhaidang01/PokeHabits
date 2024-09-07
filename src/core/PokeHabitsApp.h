#pragma once

#include <QMap>
#include <QDate>
#include "CalendarModel.h"
#include "DailyReportList.h"
#include "DailyReportModel.h"
#include "PokeApiManager.h"

class DailyReportList;

using QMapDateDailyReportModelPtr = std::shared_ptr<QMap<QDate, DailyReportModel*>>;
using QMapYearCalendarModelPtr = std::shared_ptr<QMap<int, CalendarModel*>>;

const int cDefaultDate = 0;

class PokeHabitsApp : public QObject
{
	Q_OBJECT
	Q_PROPERTY(DailyReportModel* dailyReportModel READ dailyReportModel NOTIFY selectedDateChanged FINAL)

public:
	static PokeHabitsApp* getInstance();
	DailyReportModel* dailyReportModel();

	void prepareDatabase();
	bool createDatabase(const QString& dbName);
	bool createTables();

	std::shared_ptr<QMap<QDate, ListDailyReportPtr>> readDatabase(QString username, QString password);
	bool writeDatabase(QString username, QString password, QDate date, const ListDailyReportPtr& pokeHabitList);

public slots:
	CalendarModel* getCalendarModel(int year = cDefaultDate);
	PokemonModel* pokemonModel();

	void setSelectedDate(int day, int month, int year);
	void addPokeHabit(QString habitName);

signals:
	void selectedDateChanged();

private:
	explicit PokeHabitsApp(QObject *parent = nullptr);

	void createCurrentYearCalendarList();
	void createDailyReportModelsFromDatabase();

	QMapYearCalendarModelPtr m_allCalendarModel;
	QMapDateDailyReportModelPtr m_allDailyReportModel;

	QDate m_currentDate;
	QDate m_selectedDate;

	PokeApiManager* m_pokeApiManager;

	QString m_databaseFolder;
};
