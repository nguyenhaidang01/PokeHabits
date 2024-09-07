#include "Pokemon.h"
#include "DailyReportList.h"
#include "DailyReportModel.h"

DailyReportModel::DailyReportModel(QObject *parent)
    : QAbstractListModel{parent}
    , m_dailyReportList{ std::make_shared<DailyReportList>() }
{
	QObject::connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemAppended, this, &DailyReportModel::countChanged);
	QObject::connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemAppended, this, &DailyReportModel::countChanged);
}

DailyReportModel::DailyReportModel(std::shared_ptr<DailyReportList> dailyReportList, QObject *parent)
    : QAbstractListModel{parent}
    , m_dailyReportList{dailyReportList}
{
	QObject::connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemAppended, this, &DailyReportModel::countChanged);
	QObject::connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemAppended, this, &DailyReportModel::countChanged);
}

int DailyReportModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid() || !m_dailyReportList)
		return 0;

	return m_dailyReportList->items()->size();
}

QVariant DailyReportModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_dailyReportList)
		return QVariant();

	const std::shared_ptr<PokeHabit> item = m_dailyReportList->items()->at(index.row());
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
	if (!m_dailyReportList)
		return false;

	std::shared_ptr<PokeHabit> item = m_dailyReportList->items()->at(index.row());

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

	if (m_dailyReportList->setDailyReporItemAt(index.row(), item)) {
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
	names[PokemonHpStatRole] = "pkmHpStat";
	names[PokemonAttackRole] = "pkmAttack";
	names[PokemonDefenseRole] = "pkmDefense";
	names[PokemonSAttackRole] =	"pkmSAttack";
	names[PokemonSDefenseRole] = "pkmSDefense";
	names[PokemonSpeedRole] = "pkmSpeed";
	names[PokemonImageSvgRole] = "pkmImageSvg";
	names[PokemonImagePngRole] = "pkmImagePng";

	return names;
}

std::shared_ptr<DailyReportList> DailyReportModel::dailyReportList() const
{
	return m_dailyReportList;
}

void DailyReportModel::setDailyReportList(std::shared_ptr<DailyReportList> list)
{
	beginResetModel();

	if (m_dailyReportList) {
		m_dailyReportList->disconnect(this);
	}

	m_dailyReportList = list;

	if (m_dailyReportList) {
		connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemAppended, this, [=]() {
			const int index = m_dailyReportList->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_dailyReportList.get(), &DailyReportList::preDailyReportItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_dailyReportList.get(), &DailyReportList::postDailyReportItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}

int DailyReportModel::count()
{
	return m_dailyReportList->items()->size();
}
