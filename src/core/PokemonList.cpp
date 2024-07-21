#include "PokemonList.h"
#include "Pokemon.h"

PokemonList::PokemonList(QObject *parent)
    : QObject(parent)
    , m_list{new QList<Pokemon*>()}
{
}

PokemonList::PokemonList(QList<Pokemon*> *list, QObject *parent)
    : QObject(parent)
    , m_list{list}
{
}

QList<Pokemon*>* PokemonList::items() const
{
	return m_list;
}

bool PokemonList::setPokemonItemAt(int index, Pokemon* item)
{
	if (index < 0 || index >= m_list->size())
		return false;

	m_list->replace(index, item);
	return true;
}

void PokemonList::appendPokemonItem(Pokemon *item)
{
	emit prePokemonItemAppended();
	m_list->append(item);
	emit postPokemonItemAppended();
}
