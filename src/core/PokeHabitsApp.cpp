#include "PokeHabitsApp.h"
#include "PokemonList.h"
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
	, m_allPkmModels{ std::make_shared<QMap<QDate, PokemonModel*>>() }
	, m_currentDate{ QDate::currentDate() }
	, m_selectedDate { m_currentDate }
{
	createCurrentYearCalendarList();
	createAllPokemonModel();

    QObject::connect(this, &PokeHabitsApp::selectedDateChanged, this, [&]() {
		if (!m_allCalendarModel->contains(m_selectedDate.year())) {
			return;
		}
		m_allCalendarModel->value(m_selectedDate.year())->setSelectedDate(m_selectedDate);
	});
}

PokemonModel* PokeHabitsApp::pokemonModel()
{
	if (!m_allPkmModels->contains(m_selectedDate)) {
		return nullptr;
	}
	return m_allPkmModels->value(m_selectedDate);
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

void PokeHabitsApp::createAllPokemonModel()
{
	if (!m_allPkmModels) {
		return;
	}
	
	std::shared_ptr<Pokemon> pkmItem1 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem2 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem3 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem4 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem5 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem6 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem7 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem8 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	std::shared_ptr<Pokemon> pkmItem9 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	
	std::shared_ptr<PokemonList> pkmList = std::make_shared<PokemonList>();
	pkmList->appendPokemonItem(pkmItem1);
	pkmList->appendPokemonItem(pkmItem2);
	pkmList->appendPokemonItem(pkmItem3);
	pkmList->appendPokemonItem(pkmItem4);
	pkmList->appendPokemonItem(pkmItem5);
	pkmList->appendPokemonItem(pkmItem6);
	pkmList->appendPokemonItem(pkmItem7);
	pkmList->appendPokemonItem(pkmItem8);
	pkmList->appendPokemonItem(pkmItem9);
	
	PokemonModel* pkmModel = new PokemonModel();
	pkmModel->setPokemonList(pkmList);
		
	m_allPkmModels->insert(m_currentDate, pkmModel);
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
