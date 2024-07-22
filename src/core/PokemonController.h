#pragma once

#include <QMap>
#include <QDate>
#include "PokemonModel.h"

class PokemonList;

using QMapDatePokemonModelPtr = std::shared_ptr<QMap<QDate, std::shared_ptr<PokemonModel>>>;

class PokemonController : public QObject
{
	Q_OBJECT

public:
	explicit PokemonController(QObject *parent = nullptr);

	void createAllPokemonModel();

public slots:
	PokemonModel* getPokemonModel(int day, int month, int year);
	PokemonModel* getPokemonModel(QDate &date);

private:
	QMapDatePokemonModelPtr m_allPkmModels;
};
