#pragma once

#include <QMap>
#include <QDate>

#include "PokemonModel.h"
#include "HabitModel.h"
#include "UiService.h"
#include "PokeApiService.h"

class CalendarModel;

class PokeHabitsController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(CalendarModel* calendarModel READ calendarModel CONSTANT)
	Q_PROPERTY(PokemonModel* pokemonModel READ pokemonModel CONSTANT)
	Q_PROPERTY(HabitModel* habitModel READ habitModel CONSTANT)
	Q_PROPERTY(UiService* uiService READ uiService CONSTANT)

public:
	static PokeHabitsController* getInstance();

	CalendarModel* calendarModel();
	PokemonModel* pokemonModel();
	HabitModel* habitModel();

	UiService* uiService();

signals:

public slots:
	QString getPokemonName(int id);
	QString getPokemonImage(int id);
	void appendHabit(int pokeId, QString habitName, QString targetUnit,
	                 int targetValue, QString frequency);

private slots:
	void appendPokemon(int id);

private:
	explicit PokeHabitsController(QObject *parent = nullptr);

	QVector<QDate> createCalendarListForYear(int year);
	void createPokemonModelRange(int start, int end);

	CalendarModel* m_calendarModel;
	PokemonModel* m_pokemonModel;
	HabitModel* m_habitModel;

	std::unique_ptr<PokeApiService> m_pokeApiService;
	UiService* m_uiService;

	QString m_pokemonInfoFolder;
};
