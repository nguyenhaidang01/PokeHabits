/******************************************************************************
**
** File      PokemonHelper.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "PokemonHelper.h"
#include "Pokemon.h"
#include <QFile>
#include <QDir>
#include <QStandardPaths>

namespace {

QString toQString(Type type) {
	switch(type) {
	case Type::Normal: return "Normal";
	case Type::Fire: return "Fire";
	case Type::Water: return "Water";
	case Type::Grass: return "Grass";
	case Type::Electric: return "Electric";
	case Type::Ice: return "Ice";
	case Type::Fighting: return "Fighting";
	case Type::Poison: return "Poison";
	case Type::Ground: return "Ground";
	case Type::Flying: return "Flying";
	case Type::Psychic: return "Psychic";
	case Type::Bug: return "Bug";
	case Type::Rock: return "Rock";
	case Type::Ghost: return "Ghost";
	case Type::Dragon: return "Dragon";
	case Type::Dark: return "Dark";
	case Type::Steel: return "Steel";
	case Type::Fairy: return "Fairy";
	}

	return QString();
}

}

PokemonHelper::PokemonHelper(PokemonModel* pokemonModel,
                           QString &pokemonInfoFolder, QObject *parent)
    : QObject(parent)
    , m_pokemonModel(pokemonModel)
    , m_pokemonInfoFolder(pokemonInfoFolder)
{
}

QString PokemonHelper::pokemonName(int id)
{
	return pokemonInfo(id, PokemonModel::DataRole::NameRole).toString();
}

QString PokemonHelper::pokemonImage(int id)
{
	return pokemonInfo(id, PokemonModel::DataRole::ImageRole).toString();
}

int PokemonHelper::pokemonBaseExp(int id)
{
	return pokemonInfo(id, PokemonModel::DataRole::BaseExpRole).toInt();
}

QString PokemonHelper::pokemonFirstType(int id)
{
	return pokemonInfo(id, PokemonModel::DataRole::FirstTypeRole).toString();
}

QString PokemonHelper::pokemonSecondType(int id)
{
	return pokemonInfo(id, PokemonModel::DataRole::SecondTypeRole).toString();
}

QVariant PokemonHelper::pokemonInfo(int id, PokemonModel::DataRole role)
{
	QString filePath = QDir(m_pokemonInfoFolder).filePath(QString("%1.json").arg(id));
	if (QFile::exists(filePath)) {
		for (const Pokemon &pokemon : *(m_pokemonModel->list())) {
			if (id == pokemon.id) {
				switch (role) {
				case PokemonModel::DataRole::NameRole:
					return QVariant(pokemon.name);
				case PokemonModel::DataRole::ImageRole:
					return QVariant(pokemon.image);
				case PokemonModel::DataRole::BaseExpRole:
					return QVariant(pokemon.baseExp);
				case PokemonModel::DataRole::FirstTypeRole:
					return QVariant(toQString(pokemon.types.first()));
				case PokemonModel::DataRole::SecondTypeRole:
					return pokemon.types.size() > 1 ?
					            QVariant(toQString(pokemon.types.last())) : QVariant();
				default:
					return QVariant();
				}
			}
		}
	}

	return QVariant();
}
