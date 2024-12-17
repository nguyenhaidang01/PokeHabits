#include "PokeHabitsController.h"

#define USERNAME "DangNH"
#define PASSWORD "CR7GOAT"

static PokeHabitsController* instance = nullptr;

PokeHabitsController* PokeHabitsController::getInstance()
{
	if (!instance) {
		instance = new PokeHabitsController();
	}
	return instance;
}

PokeHabitsController::PokeHabitsController(QObject *parent)
	: QObject(parent)
    , m_uiController{ new UiController() }
{
}

UiController* PokeHabitsController::uiController()
{
	return m_uiController;
}
