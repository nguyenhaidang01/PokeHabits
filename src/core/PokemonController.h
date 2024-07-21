#pragma once

#include <QMap>
#include <QDate>
#include "PokemonModel.h"

class PokemonList;

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
	QMap<QDate, PokemonModel*> *m_allPkmModels;
};
