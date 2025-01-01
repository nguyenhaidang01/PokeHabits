#pragma once

#include <QMap>
#include <QDate>

#include "HabitModel.h"
#include "PokemonModel.h"
#include "PokemonHelper.h"
#include "UiService.h"
#include "PokeApiService.h"

class CalendarModel;

class PokeHabitsController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QObject* calendarModel READ calendarModel CONSTANT)
	Q_PROPERTY(QObject* pokemonModel READ pokemonModel CONSTANT)
	Q_PROPERTY(QObject* habitModel READ habitModel CONSTANT)
	Q_PROPERTY(QObject* uiService READ uiService CONSTANT)
	Q_PROPERTY(QObject* pokemonHelper READ pokemonHelper CONSTANT)

public:
	static PokeHabitsController* getInstance();

	QObject* calendarModel();
	QObject* pokemonModel();
	QObject* habitModel();

	QObject* uiService();
	QObject* pokemonHelper();

signals:

public slots:
	void appendHabit(int pokeId, QString habitName, QString targetUnit,
	                 int targetValue, QString frequency);
	void replaceHabit(int index, int pokeId, QString habitName, QString targetUnit,
	             int targetValue, QString frequency);

private slots:
	void appendPokemon(int id);

private:
	explicit PokeHabitsController(QObject *parent = nullptr);

	void initModel();
	QVector<QDate> createCalendarListForYear(int year);
	void createPokemonModelRange(int start, int end);

	CalendarModel* m_calendarModel;
	PokemonModel* m_pokemonModel;
	HabitModel* m_habitModel;

	std::unique_ptr<PokeApiService> m_pokeApiService;
	UiService* m_uiService;

	PokemonHelper* m_pokemonHelper;
	QString m_pokemonInfoFolder;
};
