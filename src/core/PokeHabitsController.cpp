#include "PokeHabitsController.h"

#include <QFile>
#include <QDir>
#include <QStandardPaths>

#include "CalendarModel.h"
#include "PokeApiService.h"
#include "Pokemon.h"
#include "Habit.h"

#define POKEIDMAX 1008
#define POKEMONFOLDERNAME "/Pokemon"
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
    , m_habitModel{ new HabitModel() }
    , m_uiService{ new UiService() }
    , m_pokemonInfoFolder{ QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append(POKEMONFOLDERNAME) }
{
	m_pokeApiService = std::make_unique<PokeApiService>(m_pokemonInfoFolder);

	createPokemonModelRange(1, POKEIDMAX);
	m_pokemonHelper = new PokemonHelper(m_pokemonModel, m_pokemonInfoFolder);

	const auto &dates = createCalendarListForYear(QDate::currentDate().year());
	m_calendarModel = new CalendarModel(std::make_shared<QVector<QDate>>(dates));

	connect(m_calendarModel, &CalendarModel::selectedDateChanged, m_habitModel, &HabitModel::setSelectedDate);
}

CalendarModel* PokeHabitsController::calendarModel()
{
	return m_calendarModel;
}

PokemonModel* PokeHabitsController::pokemonModel()
{
	return m_pokemonModel;
}

HabitModel* PokeHabitsController::habitModel()
{
	return m_habitModel;
}

UiService* PokeHabitsController::uiService()
{
	return m_uiService;
}

PokemonHelper* PokeHabitsController::pokemonHelper()
{
	return m_pokemonHelper;
}

void PokeHabitsController::appendHabit(int pokeId, QString habitName, QString targetUnit,
                 int targetValue, QString frequency)
{
	Habit habit {
		pokeId,
		habitName,
		{}, // dates
		{	// statistics
			QDate::currentDate(),	// startDate
			        0,				// stretch
			        0,				// longestStretch
			        targetUnit,
			        targetValue,
			{} // frequency (QVector<DateOfWeek>)
		},
		{	// evolState
			0,		// exp
			1,		// lvl
			true	// hasNextForm
		}
	};

	m_habitModel->appendItem(habit);
}

void PokeHabitsController::replaceHabit(int index, int pokeId, QString habitName, QString targetUnit,
             int targetValue, QString frequency)
{
	Habit habit = m_habitModel->list()->at(index);

	habit.pokeId = pokeId;
	habit.name = habitName;
	habit.statistics.targetUnit = targetUnit;
	habit.statistics.targetValue = targetValue;

	m_habitModel->replaceItem(index, habit);
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
