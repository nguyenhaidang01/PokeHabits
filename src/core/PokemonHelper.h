/******************************************************************************
**
** File      PokemonHelper.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <QObject>
#include <PokemonModel.h>

class PokemonHelper : public QObject
{
	Q_OBJECT

public:
	explicit PokemonHelper(PokemonModel* pokemonModel,
	                       QString &pokemonInfoFolder, QObject *parent = nullptr);
public slots:
	QString pokemonName(int id);
	QString pokemonImage(int id);
	int pokemonBaseExp(int id);
	QString pokemonFirstType(int id);
	QString pokemonSecondType(int id);

private:
	QVariant pokemonInfo(int id, PokemonModel::DataRole role);

	QString m_pokemonInfoFolder;
	PokemonModel* m_pokemonModel;
};
