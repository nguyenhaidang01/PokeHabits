/******************************************************************************
**
** File      PokemonModel.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "PokemonModel.h"
#include "Pokemon.h"

namespace util {

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

PokemonModel::PokemonModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_List{ std::make_shared<QVector<Pokemon>>() }
{
}

int PokemonModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_List)
		return 0;

	return m_List->size();
}

QVariant PokemonModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_List)
		return QVariant();

	const Pokemon &item = m_List->at(index.row());
	switch (role) {
	case IdRole:
		return QVariant(item.id);
	case NameRole:
		return QVariant(item.name);
	case ImageRole:
		return QVariant(item.image);
	case BaseExpRole:
		return QVariant(item.baseExp);
	case FirstTypeRole:
		return QVariant(util::toQString(item.types.first()));
	case SecondTypeRole:
		return item.types.size() > 1 ? QVariant(util::toQString(item.types.last())) : QVariant();
	}

	return QVariant();
}

Qt::ItemFlags PokemonModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PokemonModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[IdRole] = "id";
	names[NameRole] = "name";
	names[ImageRole] = "image";
	names[BaseExpRole] = "baseExp";
	names[FirstTypeRole] = "firstType";
	names[SecondTypeRole] = "secondType";

	return names;
}

PokemonListPtr PokemonModel::list() const
{
	return m_List;
}

void PokemonModel::setList(PokemonListPtr list)
{
	beginResetModel();
	m_List = list;
	endResetModel();
}

void PokemonModel::appendItem(Pokemon &pokemon)
{
	const int index = m_List->size();
	beginInsertRows(QModelIndex(), index, index);
	m_List->append(pokemon);
	endInsertRows();
}
