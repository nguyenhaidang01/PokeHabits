#include "PokeHabitsApp.h"

#define USERNAME "DangNH"
#define PASSWORD "CR7GOAT"

static PokeHabitsApp* instance = nullptr;

PokeHabitsApp* PokeHabitsApp::getInstance()
{
	if (!instance) {
		instance = new PokeHabitsApp();
	}
	return instance;
}

PokeHabitsApp::PokeHabitsApp(QObject *parent)
	: QObject(parent)
    , m_uiController{ new UiController() }
{
}

UiController* PokeHabitsApp::uiController()
{
	return m_uiController;
}
