#include "PokemonList.h"

PokemonList::PokemonList(QObject *parent)
	: QObject(parent)
	, m_Items{ std::make_shared<QVector<std::shared_ptr<Pokemon>>>() }
{
}

QVectorPokemonPtr PokemonList::items() const
{
	return m_Items;
}

bool PokemonList::setItemAt(int index, const PokemonPtr &item)
{
	if (index < 0 || index >= m_Items->size())
		return false;

	m_Items->replace(index, item);

	return true;
}

void PokemonList::appendItem(PokemonPtr nItem)
{
	emit preItemAppended();

	m_Items->append(nItem);

	emit postItemAppended();
}

bool PokemonList::removeItemAt(int index)
{
	if (index < 0 || index >= m_Items->size())
		return false;

	emit preItemRemoved(index);

	m_Items->removeAt(index);

	emit postItemRemoved();

	return true;
}
