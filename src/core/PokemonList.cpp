#include "PokemonList.h"
#include "Pokemon.h"

PokemonList::PokemonList(QObject *parent)
	: QObject(parent)
    , m_list{std::make_shared<QList<std::shared_ptr<Pokemon>>>()}
{
}

PokemonList::PokemonList(ListPokemonPtr list, QObject *parent)
	: QObject(parent)
	, m_list{list}
{
}

ListPokemonPtr PokemonList::items() const
{
	return m_list;
}

bool PokemonList::setPokemonItemAt(int index, std::shared_ptr<Pokemon> item)
{
	if (!m_list) {
		return false;
	}

	if (index < 0 || index >= m_list->size())
		return false;

	m_list->replace(index, item);
	return true;
}

void PokemonList::appendPokemonItem(std::shared_ptr<Pokemon> item)
{
	if (!m_list) {
		return;
	}
	
	emit prePokemonItemAppended();
	m_list->append(item);
	emit postPokemonItemAppended();
}
