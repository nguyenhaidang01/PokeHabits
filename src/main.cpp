#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "core/PokeHabitsApp.h"
#include "core/Pokemon.h"
#include "core/DailyReportList.h"
#include "core/DailyReportModel.h"

int main(int argc, char *argv[])
{
	qputenv("QT_ENABLE_HIGHDPI_SCALING", "0");
	QGuiApplication app(argc, argv);

	PokeHabitsApp* pokeHabitsApp = PokeHabitsApp::getInstance();

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(QStringLiteral("pokeHabitsApp"), pokeHabitsApp);

	qmlRegisterSingletonType(QUrl("qrc:/ui/component_v1/UiStyle.qml"), "UiStyle", 1, 0, "UiStyle");
	qmlRegisterSingletonType(QUrl("qrc:/ui/component_v2/UiConstant.qml"), "UiConstant", 1, 0, "UiConstant");

	const QUrl url(u"qrc:/ui/Main.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
	                 &app, []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
