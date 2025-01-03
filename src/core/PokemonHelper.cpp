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
	if (type == Type::Unknown) {
		return QString();
	}

	auto it = pokemon_util::enumToTypeNameMap.find(type);
	if (it != pokemon_util::enumToTypeNameMap.end()) {
		return it->second;
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

QString PokemonHelper::name(int id)
{
	return pokemonInfo(id, PokemonModel::Roles::NameRole).toString();
}

QString PokemonHelper::image(int id)
{
	return pokemonInfo(id, PokemonModel::Roles::ImageRole).toString();
}

int PokemonHelper::baseExp(int id)
{
	return pokemonInfo(id, PokemonModel::Roles::BaseExpRole).toInt();
}

QString PokemonHelper::firstType(int id)
{
	return pokemonInfo(id, PokemonModel::Roles::FirstTypeRole).toString();
}

QString PokemonHelper::secondType(int id)
{
	return pokemonInfo(id, PokemonModel::Roles::SecondTypeRole).toString();
}

QVariant PokemonHelper::pokemonInfo(int id, PokemonModel::Roles role)
{
	QString filePath = QDir(m_pokemonInfoFolder).filePath(QString("%1.json").arg(id));
	if (QFile::exists(filePath)) {
		for (const Pokemon &pokemon : *(m_pokemonModel->list())) {
			if (id == pokemon.id) {
				switch (role) {
				case PokemonModel::Roles::NameRole:
					return QVariant(pokemon.name);
				case PokemonModel::Roles::ImageRole:
					return QVariant(pokemon.image);
				case PokemonModel::Roles::BaseExpRole:
					return QVariant(pokemon.baseExp);
				case PokemonModel::Roles::FirstTypeRole:
					return QVariant(toQString(pokemon.types.first()));
				case PokemonModel::Roles::SecondTypeRole:
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
