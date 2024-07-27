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

public:
	static PokemonController* getInstance();

public slots:
	PokemonModel* getPokemonModel(int day = cDefaultDate, int month = cDefaultDate, int year = cDefaultDate);
	CalendarModel* getCalendarModel(int year = cDefaultDate);

private:
	explicit PokemonController(QObject *parent = nullptr);

	void createCurrentYearCalendarList();
	void createAllPokemonModel();

	QMapYearCalendarModelPtr m_allCalendarModel;
	QMapDatePokemonModelPtr m_allPkmModels;
	QDate m_currentDate;
};
