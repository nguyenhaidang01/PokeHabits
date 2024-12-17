#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "core/PokeHabitsController.h"

int main(int argc, char *argv[])
{
	qputenv("QT_ENABLE_HIGHDPI_SCALING", "0");
	QGuiApplication app(argc, argv);

	PokeHabitsController* pokeHabitsController = PokeHabitsController::getInstance();

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(QStringLiteral("pokeHabitsController"), pokeHabitsController);

	qmlRegisterSingletonType(QUrl("qrc:/ui/component_v1/UiStyle.qml"), "UiStyle", 1, 0, "UiStyle");
	qmlRegisterSingletonType(QUrl("qrc:/ui/component_v2/UiConstant.qml"), "UiConstant", 1, 0, "UiConstant");

	const QUrl url(u"qrc:/ui/Main.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
	                 &app, []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
