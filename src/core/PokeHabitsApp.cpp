#include "PokeHabitsApp.h"
#include "DailyReportList.h"
#include "Pokemon.h"

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
	, m_currentDate{ QDate::currentDate() }
	, m_selectedDate { m_currentDate }
{
	createCurrentYearCalendarList();
    createAllDailyReportModel();

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
	
	std::shared_ptr<CalendarList> calendarList = std::make_shared<CalendarList>();
	
	while (currentDate <= endDate) {
		calendarList->appendDateItem(currentDate);
		currentDate = currentDate.addDays(1);
	}
	
	CalendarModel* calendarModel = new CalendarModel(calendarList, m_currentDate);

	m_allCalendarModel->insert(m_currentDate.year(), calendarModel);
}

void PokeHabitsApp::createAllDailyReportModel()
{
    if (!m_allDailyReportModel) {
		return;
	}
	
	std::shared_ptr<PokeHabit> pkmItem1 = std::make_shared<PokeHabit>("Habit 1", 69, false);
	std::shared_ptr<PokeHabit> pkmItem2 = std::make_shared<PokeHabit>("Habit 2", 69, false);
	std::shared_ptr<PokeHabit> pkmItem3 = std::make_shared<PokeHabit>("Habit 3", 69, false);
	std::shared_ptr<PokeHabit> pkmItem4 = std::make_shared<PokeHabit>("Habit 4", 69, false);
	std::shared_ptr<PokeHabit> pkmItem5 = std::make_shared<PokeHabit>("Habit 5", 69, false);
	std::shared_ptr<PokeHabit> pkmItem6 = std::make_shared<PokeHabit>("Habit 6", 69, false);
	std::shared_ptr<PokeHabit> pkmItem7 = std::make_shared<PokeHabit>("Habit 7", 69, false);
	std::shared_ptr<PokeHabit> pkmItem8 = std::make_shared<PokeHabit>("Habit 8", 69, false);
	std::shared_ptr<PokeHabit> pkmItem9 = std::make_shared<PokeHabit>("Habit 9", 69, false);
	
    std::shared_ptr<DailyReportList> pkmList = std::make_shared<DailyReportList>();
    pkmList->appendDailyReportItem(pkmItem1);
    pkmList->appendDailyReportItem(pkmItem2);
    pkmList->appendDailyReportItem(pkmItem3);
    pkmList->appendDailyReportItem(pkmItem4);
    pkmList->appendDailyReportItem(pkmItem5);
    pkmList->appendDailyReportItem(pkmItem6);
    pkmList->appendDailyReportItem(pkmItem7);
    pkmList->appendDailyReportItem(pkmItem8);
    pkmList->appendDailyReportItem(pkmItem9);
	
    DailyReportModel* pkmModel = new DailyReportModel();
    pkmModel->setDailyReportList(pkmList);
		
    m_allDailyReportModel->insert(m_currentDate, pkmModel);
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
	} else {
		dailyReportModel = m_allDailyReportModel->value(m_selectedDate);
	}

	Pokemon pokemon = *(pokemonModel()->list()->items()->at(pokemonModel()->currentIndex()));
	m_pokeApiManager->printPokemonInfo(pokemon);

	std::shared_ptr<PokeHabit> pokeHabit = std::make_shared<PokeHabit>(habitName, 0, false, pokemon);

	dailyReportModel->dailyReportList()->appendDailyReportItem(pokeHabit);
}
