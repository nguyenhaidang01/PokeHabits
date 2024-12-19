#include "PokeHabitsController.h"

#include "CalendarModel.h"
#include "PokeApiService.h"
#include "Pokemon.h"

#define POKEIDMAX 1008
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
    , m_pokemonModel{ new PokemonModel() }
    , m_uiService{ new UiService() }
    , m_pokeApiService{ std::make_unique<PokeApiService>() }
{
	createPokemonModelRange(1, POKEIDMAX);

	const auto &dates = createCalendarListForYear(QDate::currentDate().year());
	m_calendarModel = new CalendarModel(std::make_shared<QVector<QDate>>(dates));
}

PokemonModel* PokeHabitsController::pokemonModel()
{
	return m_pokemonModel;
}

CalendarModel* PokeHabitsController::calendarModel()
{
	return m_calendarModel;
}

UiService* PokeHabitsController::uiService()
{
	return m_uiService;
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

void PokeHabitsController::appendPokemon(int id)
{
	auto pokemon = m_pokeApiService->readJsonFile(id);
	m_pokemonModel->appendItem(pokemon);
}

void PokeHabitsController::createPokemonModelRange(int start, int end)
{
	connect(m_pokeApiService.get(), &PokeApiService::fetchJsonFileCompleted,
	        this, &PokeHabitsController::appendPokemon);
	connect(m_pokeApiService.get(), &PokeApiService::jsonFileAlreadyExists,
	        this, &PokeHabitsController::appendPokemon);
	m_pokeApiService->fetchJsonFilesInRange(start, end);
}
