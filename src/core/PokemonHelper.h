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
	QString name(int id);
	QString image(int id);
	int baseExp(int id);
	QString firstType(int id);
	QString secondType(int id);

private:
	QVariant pokemonInfo(int id, PokemonModel::Roles role);

	QString m_pokemonInfoFolder;
	PokemonModel* m_pokemonModel;
};
