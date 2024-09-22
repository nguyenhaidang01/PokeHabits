#include "Pokemon.h"
#include "DailyReportModel.h"

DailyReportModel::DailyReportModel(QObject *parent)
	: QAbstractListModel(parent)
	, m_List{ std::make_shared<DailyReportList>() }
{
	setupConnections();
}

DailyReportModel::DailyReportModel(QVector<PokeHabit> items, QObject *parent)
	: QAbstractListModel(parent)
	, m_List{ std::make_shared<DailyReportList>(items) }
{
	setupConnections();
}

DailyReportModel::DailyReportModel(DailyReportListPtr dailyReportList, QObject *parent)
	: QAbstractListModel{parent}
	, m_List{dailyReportList}
{
	setupConnections();
}

void DailyReportModel::setupConnections()
{
	QObject::connect(m_List.get(), &DailyReportList::preItemAppended, this, &DailyReportModel::countChanged);
	QObject::connect(m_List.get(), &DailyReportList::postItemAppended, this, &DailyReportModel::countChanged);
}

int DailyReportModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_List)
		return 0;

	return m_List->items()->size();
}

QVariant DailyReportModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_List)
		return QVariant();

	const DailyReportPtr item = m_List->items()->at(index.row());
	switch (role) {
	case HabitNameRole:
		return QVariant(item->habitName);
	case ExpRole:
		return QVariant(item->exp);
	case DoneRole:
		return QVariant(item->done);
	case PokemonIdRole:
		return QVariant(item->pokemon.id);
	case PokemonNameRole:
		return QVariant(item->pokemon.name);
	case PokemonBaseExpRole:
		return QVariant(item->pokemon.baseExp);
	case PokemonHpStatRole:
		return QVariant(item->pokemon.stats.hp);
	case PokemonAttackRole:
		return QVariant(item->pokemon.stats.attack);
	case PokemonDefenseRole:
		return QVariant(item->pokemon.stats.defense);
	case PokemonSAttackRole:
		return QVariant(item->pokemon.stats.sAttack);
	case PokemonSDefenseRole:
		return QVariant(item->pokemon.stats.sDefense);
	case PokemonSpeedRole:
		return QVariant(item->pokemon.stats.speed);
	case PokemonImageSvgRole:
		return QVariant(item->pokemon.imageSvg);
	case PokemonImagePngRole:
		return QVariant(item->pokemon.imagePng);
	default:
		qDebug() << "Invalid RoleName";
	}

	return QVariant();
}

bool DailyReportModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!m_List)
		return false;

	DailyReportPtr item = m_List->items()->at(index.row());

	switch (role) {
	case HabitNameRole:
		item->habitName = value.toString();
		break;
	case ExpRole:
		item->exp = value.toInt();
		break;
	case DoneRole:
		item->done = value.toBool();
		break;
	case PokemonIdRole:
		item->pokemon.id = value.toInt();
		break;
	case PokemonNameRole:
		item->pokemon.name = value.toString();
		break;
	case PokemonBaseExpRole:
		item->pokemon.baseExp = value.toInt();
		break;
	case PokemonHpStatRole:
		item->pokemon.stats.hp = value.toInt();
		break;
	case PokemonAttackRole:
		item->pokemon.stats.attack = value.toInt();
		break;
	case PokemonDefenseRole:
		item->pokemon.stats.defense = value.toInt();
		break;
	case PokemonSAttackRole:
		item->pokemon.stats.sAttack = value.toInt();
		break;
	case PokemonSDefenseRole:
		item->pokemon.stats.sDefense = value.toInt();
		break;
	case PokemonSpeedRole:
		item->pokemon.stats.speed = value.toInt();
		break;
	case PokemonImageSvgRole:
		item->pokemon.imageSvg = value.toString();
		break;
	case PokemonImagePngRole:
		item->pokemon.imagePng = value.toString();
		break;
	}

	if (m_List->setItemAt(index.row(), item)) {
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
}

Qt::ItemFlags DailyReportModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	return Qt::ItemIsEditable;
}

QHash<int, QByteArray> DailyReportModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[HabitNameRole] = "habitName";
	names[ExpRole] = "exp";
	names[DoneRole] = "done";
	names[PokemonIdRole] = "pkmId";
	names[PokemonNameRole] = "pkmName";
	names[PokemonBaseExpRole] = "pkmBaseExp";
	names[PokemonHpStatRole] = "pkmHp";
	names[PokemonAttackRole] = "pkmAttack";
	names[PokemonDefenseRole] = "pkmDefense";
	names[PokemonSAttackRole] =	"pkmSAttack";
	names[PokemonSDefenseRole] = "pkmSDefense";
	names[PokemonSpeedRole] = "pkmSpeed";
	names[PokemonImageSvgRole] = "pkmImageSvg";
	names[PokemonImagePngRole] = "pkmImagePng";

	return names;
}

DailyReportListPtr DailyReportModel::list() const
{
	return m_List;
}

void DailyReportModel::setList(DailyReportListPtr list)
{
	beginResetModel();

	if (m_List) {
		m_List->disconnect(this);
	}

	m_List = list;

	if (m_List) {
		connect(m_List.get(), &DailyReportList::preItemAppended, this, [=]() {
			const int index = m_List->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_List.get(), &DailyReportList::postItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_List.get(), &DailyReportList::preItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_List.get(), &DailyReportList::postItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}

int DailyReportModel::count()
{
	return m_List->items()->size();
}
