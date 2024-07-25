#include "PokemonController.h"
#include "PokemonList.h"
#include "Pokemon.h"

PokemonController::PokemonController(QObject *parent)
    : QObject(parent)
    , m_allCalendarModel{ std::make_shared<QMap<int, std::shared_ptr<CalendarModel>>>() }
    , m_allPkmModels{ std::make_shared<QMap<QDate, std::shared_ptr<PokemonModel>>>() }
    , m_currentDate{ QDate::currentDate() }
{
    createCurrentYearCalendarList();
    createAllPokemonModel();
}

PokemonModel* PokemonController::getPokemonModel(int day, int month, int year)
{
	QDate date(year, month, day);
	if (day == month == year == cDefaultDate) {
		date = QDate(m_currentDate);
	}

	if (!m_allPkmModels->contains(date)) {
		return nullptr;
	}
	return m_allPkmModels->value(date).get();
}

CalendarModel* PokemonController::getCalendarModel(int year)
{
	if (year == cDefaultDate) {
		year = m_currentDate.year();
	}
	
	if (!m_allCalendarModel->contains(year)) {
		return nullptr;
	}
	return m_allCalendarModel->value(year).get();
}

void PokemonController::createCurrentYearCalendarList()
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
		calendarList->appendDateItem(std::make_shared<QDate>(currentDate));
		currentDate = currentDate.addDays(1);
	}
	
	std::shared_ptr<CalendarModel> calendarModel = std::make_shared<CalendarModel>(calendarList);

	m_allCalendarModel->insert(m_currentDate.year(), calendarModel);
}

void PokemonController::createAllPokemonModel()
{
	if (!m_allPkmModels) {
		return;
	}
	
    std::shared_ptr<Pokemon> pkmItem1 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
    std::shared_ptr<Pokemon> pkmItem2 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
    std::shared_ptr<Pokemon> pkmItem3 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
    std::shared_ptr<Pokemon> pkmItem4 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	
    std::shared_ptr<PokemonList> pkmList = std::make_shared<PokemonList>();
	pkmList->appendPokemonItem(pkmItem1);
	pkmList->appendPokemonItem(pkmItem2);
	pkmList->appendPokemonItem(pkmItem3);
	pkmList->appendPokemonItem(pkmItem4);
	
    std::shared_ptr<PokemonModel> pkmModel = std::make_shared<PokemonModel>();
	pkmModel->setPokemonList(pkmList);
		
    m_allPkmModels->insert(m_currentDate, pkmModel);
}
