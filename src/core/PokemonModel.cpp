#include "Pokemon.h"
#include "PokemonList.h"
#include "PokemonModel.h"

PokemonModel::PokemonModel(QObject *parent)
    : QAbstractListModel{parent}
    , m_pkmList{nullptr}
{
}

PokemonModel::PokemonModel(std::shared_ptr<PokemonList> pkmList, QObject *parent)
    : QAbstractListModel{parent}
    , m_pkmList{pkmList}
{
}

int PokemonModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_pkmList)
		return 0;

	return m_pkmList->items()->size();
}

QVariant PokemonModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_pkmList)
		return QVariant();

	const std::shared_ptr<Pokemon> item = m_pkmList->items()->at(index.row());
	switch (role) {
	case sIndexRole:
		return QVariant(item->sIndex);
	case eIndexRole:
		return QVariant(item->eIndex);
	case cIndexRole:
		return QVariant(item->cIndex);
	case NameRole:
		return QVariant(item->name);
	case ImageRole:
		return QVariant(item->image);
	case ExpRole:
		return QVariant(item->exp);
	case DoneRole:
		return QVariant(item->done);
	}

	return QVariant();
}

bool PokemonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!m_pkmList)
		return false;

	std::shared_ptr<Pokemon> item = m_pkmList->items()->at(index.row());
	switch (role) {
	case sIndexRole:
		item->sIndex = value.toInt();
		break;
	case eIndexRole:
		item->eIndex = value.toInt();
		break;
	case cIndexRole:
		item->cIndex = value.toInt();
		break;
	case NameRole:
		item->name = value.toString();
		break;
	case ImageRole:
		item->image = value.toString();
		break;
	case ExpRole:
		item->exp = value.toInt();
		break;
	case DoneRole:
		item->done = value.toBool();
		break;
	}

	if (m_pkmList->setPokemonItemAt(index.row(), item)) {
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
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
	names[sIndexRole] = "sIndex";
	names[eIndexRole] = "eIndex";
	names[cIndexRole] = "cIndex";
	names[NameRole] = "name";
	names[ImageRole] = "image";
	names[ExpRole] = "exp";
	names[DoneRole] = "done";

	return names;
}

std::shared_ptr<PokemonList> PokemonModel::pokemonList() const
{
	return m_pkmList;
}

void PokemonModel::setPokemonList(std::shared_ptr<PokemonList> list)
{
	beginResetModel();

	if (m_pkmList) {
		m_pkmList->disconnect(this);
	}

	m_pkmList = list;

	if (m_pkmList) {
		connect(m_pkmList.get(), &PokemonList::prePokemonItemAppended, this, [=]() {
			const int index = m_pkmList->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_pkmList.get(), &PokemonList::postPokemonItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_pkmList.get(), &PokemonList::prePokemonItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_pkmList.get(), &PokemonList::postPokemonItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}
