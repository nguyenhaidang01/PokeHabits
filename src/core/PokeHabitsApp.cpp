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
	, m_viewController{ new ViewController() }
{
}

ViewController* PokeHabitsApp::viewController()
{
	return m_viewController;
}
