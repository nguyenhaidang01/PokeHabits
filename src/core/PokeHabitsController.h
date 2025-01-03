#pragma once

#include <QMap>
#include <QDate>

#include "HabitModel.h"
#include "PokemonModel.h"
#include "PokemonHelper.h"
#include "UiService.h"
#include "PokeApiService.h"
#include "Repository.h"

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
	void initConnection();

	QVector<QDate> createCalendarListForYear(int year);
	void createPokemonModelRange(int start, int end);

	void saveHabits();

	CalendarModel* m_calendarModel;
	PokemonModel* m_pokemonModel;
	HabitModel* m_habitModel;

	UiService* m_uiService;
	std::unique_ptr<PokeApiService> m_pokeApiService;
	std::unique_ptr<Repository> m_repository;

	PokemonHelper* m_pokemonHelper;
	Account m_account;
};
