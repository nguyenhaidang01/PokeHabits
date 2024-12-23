/******************************************************************************
**
** File      HabitModel.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "HabitModel.h"
#include "Habit.h"

HabitModel::HabitModel(HabitListPtr habitListPtr, QObject *parent)
	: QAbstractListModel(parent)
    , m_List{ habitListPtr }
{
}

HabitModel::HabitModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_List{ std::make_shared<QVector<Habit>>() }
{
}

int HabitModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_List)
		return 0;

	return m_List->size();
}

QVariant HabitModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_List)
		return QVariant();

	const Habit &item = m_List->at(index.row());
	switch (role) {
	case NameRole:
		return QVariant(item.name);
	case PokeIdRole:
		return QVariant(item.pokeId);
	case PokeExpRole:
		return QVariant(item.evolState.exp);
	case PokeLvlRole:
		return QVariant(item.evolState.lvl);
	case PokeHasNextFormRole:
		return QVariant(item.evolState.hasNextForm);
	case StartDateRole:
		return QVariant(item.statistics.startDate);
	case StretchRole:
		return QVariant(item.statistics.stretch);
	case LongestStretchRole:
		return QVariant(item.statistics.longestStretch);
	case TargetUnitRole:
		return QVariant(item.statistics.targetUnit);
	case TargetValueRole:
		return QVariant(item.statistics.targetValue);
	case FrequencyRole:
		return QVariant("everyday"); // TODO
	}

	return QVariant();
}

Qt::ItemFlags HabitModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	return Qt::ItemIsEditable;
}

QHash<int, QByteArray> HabitModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[NameRole] = "name";
	names[PokeIdRole] = "pokeId";
	names[PokeExpRole] = "pokeExp";
    names[PokeLvlRole] = "pokeLvl";
	names[PokeHasNextFormRole] = "pokeHasNextForm";
	names[StartDateRole] = "startDate";
	names[StretchRole] = "stretch";
	names[LongestStretchRole] = "longestStretch";
	names[TargetUnitRole] = "targetUnit";
	names[TargetValueRole] = "targetValue";
	names[FrequencyRole] = "frequency";

	return names;
}

HabitListPtr HabitModel::list() const
{
	return m_List;
}

void HabitModel::setList(HabitListPtr list)
{
	beginResetModel();
	m_List = list;
	endResetModel();
}

void HabitModel::appendItem(Habit &habit)
{
	const int index = m_List->size();
	beginInsertRows(QModelIndex(), index, index);
	m_List->append(habit);
	endInsertRows();
}

void HabitModel::replaceItem(int index, Habit &habit)
{
	beginInsertRows(QModelIndex(), index, index);
	m_List->replace(index, habit);
	endInsertRows();
}

int HabitModel::selectedHabitIndex() const
{
	return m_selectedHabitIndex;
}

void HabitModel::setSelectedHabitIndex(int newSelectedHabitIndex)
{
	if (m_selectedHabitIndex == newSelectedHabitIndex) {
		return;
	}
	m_selectedHabitIndex = newSelectedHabitIndex;
	emit selectedHabitIndexChanged();
}

QVariantMap HabitModel::get(int index) const
{
	if (index < 0 || index >= m_List->size()) {
		return QVariantMap();
	}

	const auto &item = m_List->at(index);
	return QVariantMap {
			{"name", item.name},
			{"pokeId", item.pokeId},
			{"pokeExp", item.evolState.exp},
			{"pokeLvl", item.evolState.lvl},
			{"pokeHasNextForm", item.evolState.hasNextForm},
			{"startDate", item.statistics.startDate.toString("MMMM d, yyyy")},
			{"stretch", item.statistics.stretch},
			{"longestStretch", item.statistics.longestStretch},
			{"targetUnit", item.statistics.targetUnit},
			{"targetValue", item.statistics.targetValue},
			{"frequency", "everyday"} // TODO
		};
}
