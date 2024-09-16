#include "PokeHabitsApp.h"
#include "Pokemon.h"

#define USERNAME "DangNH"
#define PASSWORD "CR7GOAT"

static PokeHabitsApp* instance = nullptr;

PokeHabitsApp* PokeHabitsApp::getInstance()
{
	if (!instance) {
		instance = new PokeHabitsApp();
	}
	return instance;
}

PokeHabitsApp::PokeHabitsApp(QObject *parent)
	: QObject(parent)
	, m_allCalendarModel{ std::make_shared<QMap<int, CalendarModel*>>() }
	, m_allDailyReportModel{ std::make_shared<QMap<QDate, DailyReportModel*>>() }
	, m_pokeApiManager{ new PokeApiManager() }
	, m_databaseManager{ new DatabaseManager() }
	, m_currentDate{ QDate::currentDate() }
	, m_selectedDate { m_currentDate }
{
	createCurrentYearCalendarList();
	createDailyReportModelsFromDatabase();

	QObject::connect(this, &PokeHabitsApp::selectedDateChanged, this, [&]() {
		if (!m_allCalendarModel->contains(m_selectedDate.year())) {
			return;
		}
		m_allCalendarModel->value(m_selectedDate.year())->setSelectedDate(m_selectedDate);
	});

	m_pokeApiManager->initPokemonModel();
}

DailyReportModel* PokeHabitsApp::dailyReportModel()
{
	if (!m_allDailyReportModel->contains(m_selectedDate)) {
		return nullptr;
	}
	return m_allDailyReportModel->value(m_selectedDate);
}

CalendarModel* PokeHabitsApp::getCalendarModel(int year)
{
	if (year == cDefaultDate) {
		year = m_currentDate.year();
	}

	if (!m_allCalendarModel->contains(year)) {
		return nullptr;
	}
	return m_allCalendarModel->value(year);
}

PokemonModel* PokeHabitsApp::pokemonModel()
{
	return m_pokeApiManager->pokemonModel();
}

void PokeHabitsApp::createCurrentYearCalendarList()
{
	if (!m_allCalendarModel) {
		return;
	}

	if (m_allCalendarModel->contains(m_currentDate.year())) {
		return;
	}

	QDate startDate(m_currentDate.year(), 1, 1);
	QDate endDate(m_currentDate.year(), 12, 31);
	
	QDate currentDate = startDate;
	
	CalendarListPtr calendarList = std::make_shared<CalendarList>();
	
	while (currentDate <= endDate) {
		calendarList->appendItem(currentDate);
		currentDate = currentDate.addDays(1);
	}
	
	CalendarModel* calendarModel = new CalendarModel(calendarList, m_currentDate);

	m_allCalendarModel->insert(m_currentDate.year(), calendarModel);
}

void PokeHabitsApp::createDailyReportModelsFromDatabase()
{
	if (!m_allDailyReportModel) {
		return;
	}

	QMapDateVectorDailyReportPtr dateReportMap = m_databaseManager->readDatabase(USERNAME, PASSWORD);
	if (!dateReportMap) {
		return;
	}

	for (auto it = dateReportMap->begin(); it != dateReportMap->end(); ++it) {
		QDate date = it.key();
		QVectorDailyReportPtr habitList = it.value();

		DailyReportListPtr dailyReportList = std::make_shared<DailyReportList>(habitList);

		DailyReportModel* pkmModel = new DailyReportModel(dailyReportList);

		m_allDailyReportModel->insert(date, pkmModel);
	}

	createCurrentDateReport();
}

void PokeHabitsApp::createCurrentDateReport()
{
	if (m_allDailyReportModel->count() == 0) {
		return;
	}

	if (m_allDailyReportModel->contains(m_currentDate)) {
		return;
	}

	QMap<QDate, DailyReportModel*>::const_iterator it = m_allDailyReportModel->constEnd();
	--it;

	QVector<PokeHabit> remainingPokeHabits = it.value()->list()->itemsClone();

	for (QDate date = it.key().addDays(1); date <= m_currentDate; date = date.addDays(1)) {
		DailyReportModel* dailyReportModel = new DailyReportModel(remainingPokeHabits);
		dailyReportModel->list()->setUndoneAllItems();

		m_allDailyReportModel->insert(date, dailyReportModel);
		m_databaseManager->writeDatabase(USERNAME, PASSWORD, date, dailyReportModel->list()->items());

		qDebug() << "Create DailyReportModel of " << date.toString("yyyy-MM-dd");
	}
}

void PokeHabitsApp::setSelectedDate(int day, int month, int year)
{
	QDate newSelectedDate = QDate(year, month, day);
	if (m_selectedDate == newSelectedDate) {
		return;
	}
	m_selectedDate = newSelectedDate;
	emit selectedDateChanged();
}

void PokeHabitsApp::addPokeHabit(QString habitName)
{
	DailyReportModel* dailyReportModel;

	if (!m_allDailyReportModel->contains(m_selectedDate)) {
		dailyReportModel = new DailyReportModel();
		m_allDailyReportModel->insert(m_selectedDate, dailyReportModel);
	} else {
		dailyReportModel = m_allDailyReportModel->value(m_selectedDate);
	}

	Pokemon pokemon = *(pokemonModel()->list()->items()->at(pokemonModel()->currentIndex()));

	DailyReportPtr pokeHabit = std::make_shared<PokeHabit>(habitName, 0, false, pokemon);

	dailyReportModel->list()->appendItem(pokeHabit);
	m_databaseManager->writeDatabase(USERNAME, PASSWORD, m_selectedDate, dailyReportModel->list()->items());

	emit selectedDateChanged();
}
