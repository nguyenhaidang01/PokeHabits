#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "core/PokeHabitsApp.h"
#include "core/Pokemon.h"
#include "core/PokemonList.h"
#include "core/PokemonModel.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	PokeHabitsApp* pokeHabitsApp = PokeHabitsApp::getInstance();

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(QStringLiteral("pokeHabitsApp"), pokeHabitsApp);

	qmlRegisterSingletonType(QUrl("qrc:/ui/component/UiStyle.qml"), "UiStyle", 1, 0, "UiStyle");
	const QUrl url(u"qrc:/ui/Main.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
	                 &app, []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
