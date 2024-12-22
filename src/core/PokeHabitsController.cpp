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

	const auto &dates = createCalendarListForYear(QDate::currentDate().year());
	m_calendarModel = new CalendarModel(std::make_shared<QVector<QDate>>(dates));
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

QString PokeHabitsController::getPokemonName(int id)
{
	QString filePath = QDir(m_pokemonInfoFolder).filePath(QString("%1.json").arg(id));
	if (QFile::exists(filePath)) {
		for (const Pokemon &pokemon : *(m_pokemonModel->list())) {
			if (pokemon.id == id) {
				return pokemon.name;
			}
		}
	}

	return QString();
}

QString PokeHabitsController::getPokemonImage(int id)
{
	QString filePath = QDir(m_pokemonInfoFolder).filePath(QString("%1.json").arg(id));
	if (QFile::exists(filePath)) {
		for (const Pokemon &pokemon : *(m_pokemonModel->list())) {
			if (pokemon.id == id) {
				return pokemon.image;
			}
		}
	}

	return QString();
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
