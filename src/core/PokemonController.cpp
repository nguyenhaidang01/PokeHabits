#include "PokemonController.h"
#include "PokemonList.h"
#include "Pokemon.h"

PokemonController::PokemonController(QObject *parent)
	: QObject(parent)
    , m_allPkmModels{std::make_shared<QMap<QDate, std::shared_ptr<PokemonModel>>>()}
{
	createAllPokemonModel();
}

PokemonModel* PokemonController::getPokemonModel(QDate &date)
{
	if (m_allPkmModels->contains(date)) {
		return m_allPkmModels->value(date).get();
	}
}

PokemonModel* PokemonController::getPokemonModel(int day, int month, int year)
{
	QDate date(year, month, day);
	if (m_allPkmModels->contains(date)) {
		return m_allPkmModels->value(date).get();
	}
}

void PokemonController::createAllPokemonModel()
{
    std::shared_ptr<Pokemon> pkmItem1 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
    std::shared_ptr<Pokemon> pkmItem2 = std::make_shared<Pokemon>(3, 6, 3, "Scythe", "qrc:/ui/assets/Scythe.png", 0, false);
    std::shared_ptr<Pokemon> pkmItem3 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
    std::shared_ptr<Pokemon> pkmItem4 = std::make_shared<Pokemon>(6, 9, 6, "Leafeon", "qrc:/ui/assets/Leafeon.png", 0, false);
	
    std::shared_ptr<PokemonList> pkmList = std::make_shared<PokemonList>();
	pkmList->appendPokemonItem(pkmItem1);
	pkmList->appendPokemonItem(pkmItem2);
	pkmList->appendPokemonItem(pkmItem3);
	pkmList->appendPokemonItem(pkmItem4);
	
    std::shared_ptr<PokemonModel> pkmModel = std::make_shared<PokemonModel>();
	pkmModel->setPokemonList(pkmList);
	
	QDate date(2024, 7, 10);
	
	m_allPkmModels->insert(date, pkmModel);
}
