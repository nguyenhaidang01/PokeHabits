#pragma once

#include <QMap>
#include <QDate>

#include "PokemonModel.h"
#include "UiService.h"
#include "PokeApiService.h"

class CalendarModel;

class PokeHabitsController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(CalendarModel* calendarModel READ calendarModel CONSTANT)
	Q_PROPERTY(PokemonModel* pokemonModel READ pokemonModel CONSTANT)
	Q_PROPERTY(UiService* uiService READ uiService CONSTANT)

public:
	static PokeHabitsController* getInstance();

	CalendarModel* calendarModel();
	PokemonModel* pokemonModel();

	UiService* uiService();

signals:

private slots:
	void appendPokemon(int id);

private:
	explicit PokeHabitsController(QObject *parent = nullptr);

	QVector<QDate> createCalendarListForYear(int year);
	void createPokemonModelRange(int start, int end);

	PokemonModel* m_pokemonModel;
	CalendarModel* m_calendarModel;

	std::unique_ptr<PokeApiService> m_pokeApiService;
	UiService* m_uiService;
};
