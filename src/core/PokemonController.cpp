#include "PokemonController.h"
#include "PokemonList.h"
#include "Pokemon.h"

PokemonController::PokemonController(QObject *parent)
    : QObject(parent)
    , m_allPkmModels{new QMap<QDate, PokemonModel*>()}
{
	createAllPokemonModel();
}

PokemonModel* PokemonController::getPokemonModel(QDate &date)
{
	if (m_allPkmModels->contains(date)) {
		return m_allPkmModels->value(date);
	}
}

PokemonModel* PokemonController::getPokemonModel(int day, int month, int year)
{
	QDate date(year, month, day);
	if (m_allPkmModels->contains(date)) {
		return m_allPkmModels->value(date);
	}
}

void PokemonController::createAllPokemonModel()
{
	Pokemon *pkmItem1 = new Pokemon{3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false};
	Pokemon *pkmItem2 = new Pokemon{3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false};
	Pokemon *pkmItem3 = new Pokemon{6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false};
	Pokemon *pkmItem4 = new Pokemon{6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false};

	PokemonList* pkmList = new PokemonList();
	pkmList->appendPokemonItem(pkmItem1);
	pkmList->appendPokemonItem(pkmItem2);
	pkmList->appendPokemonItem(pkmItem3);
	pkmList->appendPokemonItem(pkmItem4);

	PokemonModel* pkmModel = new PokemonModel();
	pkmModel->setPokemonList(pkmList);

	QDate date(2024, 7, 10);

	m_allPkmModels->insert(date, pkmModel);
}
