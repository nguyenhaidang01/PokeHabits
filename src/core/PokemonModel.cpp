#include "PokemonModel.h"

PokemonModel::PokemonModel(QObject *parent)
	: QAbstractListModel(parent)
	, m_List{ std::make_shared<PokemonList>() }
    , m_currentIndex{ 0 }
{
}

int PokemonModel::rowCount(const QModelIndex &parent) const
{
	// For list models only the root node (an invalid parent) should return the list's size. For all
	// other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
	if (parent.isValid() || !m_List)
		return 0;

	return m_List->items()->size();
}

QVariant PokemonModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !m_List)
		return QVariant();

	const PokemonPtr item = m_List->items()->at(index.row());

	switch (role) {
	case IdRole:
		return QVariant(item->id);
	case NameRole:
		return QVariant(item->name);
	case BaseExpRole:
		return QVariant(item->baseExp);
	case HpStatRole:
		return QVariant(item->stats.hp);
	case AttackRole:
		return QVariant(item->stats.attack);
	case DefenseRole:
		return QVariant(item->stats.defense);
	case SAttackRole:
		return QVariant(item->stats.sAttack);
	case SDefenseRole:
		return QVariant(item->stats.sDefense);
	case SpeedRole:
		return QVariant(item->stats.speed);
	case ImageSvgRole:
		return QVariant(item->imageSvg);
	case ImagePngRole:
		return QVariant(item->imagePng);
	default:
		qDebug() << "Invalid RoleName";
	}

	return QVariant();
}

bool PokemonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!m_List)
		return false;

	PokemonPtr item = m_List->items()->at(index.row());
	switch (role) {
	case IdRole:
		item->id = value.toInt();
		break;
	case NameRole:
		item->name = value.toString();
		break;
	case BaseExpRole:
		item->baseExp = value.toInt();
		break;
	case HpStatRole:
		item->stats.hp = value.toInt();
		break;
	case AttackRole:
		item->stats.attack = value.toInt();
		break;
	case DefenseRole:
		item->stats.defense = value.toInt();
		break;
	case SAttackRole:
		item->stats.sAttack = value.toInt();
		break;
	case SDefenseRole:
		item->stats.sDefense = value.toInt();
		break;
	case SpeedRole:
		item->stats.speed = value.toInt();
		break;
	case ImageSvgRole:
		item->imageSvg = value.toString();
		break;
	case ImagePngRole:
		item->imagePng = value.toString();
		break;
	}

	if (m_List->setItemAt(index.row(), item)) {
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

	names[IdRole] = "id";
	names[NameRole] = "name";
	names[BaseExpRole] = "baseExp";
	names[HpStatRole] = "hp";
	names[AttackRole] = "attack";
	names[DefenseRole] = "defense";
	names[SAttackRole] = "sAttack";
	names[SDefenseRole] = "sDefense";
	names[SpeedRole] = "speed";
	names[ImageSvgRole] = "imageSvg";
	names[ImagePngRole] = "imagePng";

	return names;
}

PokemonListPtr PokemonModel::list() const
{
	return m_List;
}

void PokemonModel::setList(PokemonListPtr list)
{
	beginResetModel();

	if (m_List)
		m_List->disconnect(this);

	m_List = list;

	if (m_List) {
		connect(m_List.get(), &PokemonList::preItemAppended, this, [=]() {
			const int index = m_List->items()->size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(m_List.get(), &PokemonList::postItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(m_List.get(), &PokemonList::preItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(m_List.get(), &PokemonList::postItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}

void PokemonModel::refreshList() {
	beginResetModel();

	endResetModel();
}

int PokemonModel::currentIndex() {
	return m_currentIndex;
}

void PokemonModel::setCurrentIndex(int nCurrentIndex) {
	if (m_currentIndex == nCurrentIndex) {
		return;
	}
	m_currentIndex = nCurrentIndex;

	emit currentIndexChanged();
}

QString PokemonModel::currentItemName() {
	return m_List->items()->at(m_currentIndex)->name;
}
