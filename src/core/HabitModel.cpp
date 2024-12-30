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
    , m_selectedDate{ QDate::currentDate() }
{
	initConnection();
}

HabitModel::HabitModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_List{ std::make_shared<QVector<Habit>>() }
    , m_selectedDate{ QDate::currentDate() }
{
	initConnection();
}

void HabitModel::initConnection()
{
	connect(this, &HabitModel::selectedDateChanged, this, [this]() {
	for (int index = 0; index < m_List->size(); ++index) {
		emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << IsExistRole);
		emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << DoneRole);
		emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << PokeExpRole);
	}
	});
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
	case DoneRole:
		return QVariant(item.dates.contains(m_selectedDate));
	case IsExistRole:
		return QVariant(m_selectedDate >= item.statistics.startDate);
	case PokeIdRole:
		return QVariant(item.pokeId);
	case PokeExpRole:
		return QVariant(item.evolState.exp);
	case PokeLvlRole:
		return QVariant(item.evolState.lvl);
	case PokeHasNextFormRole:
		return QVariant(item.evolState.hasNextForm);
	case StartDateStrRole:
		return QVariant(item.statistics.startDate.toString("MMMM d, yyyy"));
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

bool HabitModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!index.isValid() || !m_List) {
		return false;
	}

	Habit item = m_List->at(index.row());
	switch (role) {
	case NameRole:
		item.name = value.toString();
		break;
	case PokeIdRole:
		item.pokeId = value.toInt();
		break;
	case PokeExpRole:
		item.evolState.exp = value.toInt();
		break;
	case PokeLvlRole:
		item.evolState.lvl = value.toInt();
		break;
	case PokeHasNextFormRole:
		item.evolState.hasNextForm = value.toBool();
		break;
	case StartDateStrRole:
		item.statistics.startDate = value.toDate();
		break;
	case StretchRole:
		item.statistics.stretch = value.toInt();
		break;
	case LongestStretchRole:
		item.statistics.longestStretch = value.toInt();
		break;
	case TargetValueRole:
		item.statistics.targetValue = value.toInt();
		break;
	case TargetUnitRole:
		item.statistics.targetUnit = value.toString();
		break;
	}

	if (replaceItem(index.row(), item)) {
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
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
	names[DoneRole] = "done";
	names[IsExistRole] = "isExist";
	names[PokeIdRole] = "pokeId";
	names[PokeExpRole] = "pokeExp";
	names[PokeLvlRole] = "pokeLvl";
	names[PokeHasNextFormRole] = "pokeHasNextForm";
	names[StartDateStrRole] = "startDateStr";
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
	m_List = list;
}

void HabitModel::appendItem(Habit &habit)
{
	const int index = m_List->size();
	beginInsertRows(QModelIndex(), index, index);
	m_List->append(habit);
	endInsertRows();
}

bool HabitModel::replaceItem(int index, Habit &habit)
{
	if (index < 0 || index >= m_List->size()) {
		return false;
	}

	m_List->replace(index, habit);
	return true;
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

void HabitModel::setSelectedDate(QDate newSelectedDate)
{
	if (newSelectedDate == m_selectedDate) {
		return;
	}
	m_selectedDate = newSelectedDate;
	emit selectedDateChanged();
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
			{"startDateStr", item.statistics.startDate.toString("MMMM d, yyyy")},
			{"stretch", item.statistics.stretch},
			{"longestStretch", item.statistics.longestStretch},
			{"targetUnit", item.statistics.targetUnit},
			{"targetValue", item.statistics.targetValue},
			{"frequency", "everyday"} // TODO
		};
}

void HabitModel::toggleDoneStatus(const int index, QString selectedDateStr)
{
	QDate selectedDate = QDate::fromString(selectedDateStr, "MMMM d, yyyy");
	Habit habit = m_List->at(index);

	if (habit.dates.contains(selectedDate)) {
		habit.dates.removeOne(selectedDate);
		habit.evolState.exp--;
		habit.statistics.stretch--;
	} else {
		habit.dates.push_back(selectedDate);
		habit.evolState.exp++;
		habit.statistics.stretch++;
	}

	replaceItem(index, habit);
	emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << DoneRole);
	emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << PokeExpRole);
	emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << StretchRole);
}
