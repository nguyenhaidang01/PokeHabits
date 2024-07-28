#pragma once

#include <QMap>
#include <QDate>
#include "CalendarModel.h"
#include "PokemonModel.h"

class PokemonList;

using QMapDatePokemonModelPtr = std::shared_ptr<QMap<QDate, PokemonModel*>>;
using QMapYearCalendarModelPtr = std::shared_ptr<QMap<int, CalendarModel*>>;

const int cDefaultDate = 0;

class PokemonController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(PokemonModel* pokemonModel READ pokemonModel NOTIFY selectedDateChanged FINAL)

public:
	static PokemonController* getInstance();
	PokemonModel* pokemonModel();

public slots:
	CalendarModel* getCalendarModel(int year = cDefaultDate);

	void setSelectedDate(int day, int month, int year);

signals:
	void selectedDateChanged();

private:
	explicit PokemonController(QObject *parent = nullptr);

	void createCurrentYearCalendarList();
	void createAllPokemonModel();

	QMapYearCalendarModelPtr m_allCalendarModel;
	QMapDatePokemonModelPtr m_allPkmModels;

	QDate m_currentDate;
	QDate m_selectedDate;
};
