#include <memory>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QThread>
#include <QtConcurrent>
#include <QFutureWatcher>
#include <QGuiApplication>
#include <QDebug>
#include "PokeApiManager.h"
#include "PokemonList.h"

#define POKEMONINFOFOLDERNAME "/PokemonInfo"
#define HIGHESTINDEX 100

PokeApiManager::PokeApiManager(QObject* parent)
	: QObject(parent)
	, m_pokemonInfoFolder { QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append(POKEMONINFOFOLDERNAME) }
	, m_cancelled{ false }
	, m_pokemonModel{ new PokemonModel() }
{
	QDir dir(m_pokemonInfoFolder);
	if (!dir.exists()) {
		if (dir.mkpath(".")) {
			qDebug() << "PokeHabits AppData folder has been created:" << m_pokemonInfoFolder;
		} else {
			qDebug() << "Cannot create folder:" << m_pokemonInfoFolder;
		}
	}

	connect(QGuiApplication::instance(), &QGuiApplication::aboutToQuit, this, &PokeApiManager::cancelInitPokemonModel);
}

PokemonModel* PokeApiManager::pokemonModel() {
	return m_pokemonModel;
}

void PokeApiManager::initPokemonModel() {
	m_future = QtConcurrent::run([this]() { loadPokemons(); });
	m_watcher.setFuture(m_future);

	connect(&m_watcher, &QFutureWatcher<void>::finished, this, &PokeApiManager::onLoadFinished);
}

void PokeApiManager::cancelInitPokemonModel() {
	m_cancelled.store(true);

	m_future.cancel();
	m_future.waitForFinished();
}

void PokeApiManager::loadPokemons() {
	for (int id = 1; id <= HIGHESTINDEX; ++id) {
		if (id % 50 == 0) {
			m_pokemonModel->refreshList();
		}

		if (m_cancelled.load()) {
			qDebug() << "Loading cancelled.";
			break;
		}

		QString fileName = QString("%1.json").arg(id);
		QString filePath = QDir(m_pokemonInfoFolder).filePath(fileName);

		if (QFile::exists(filePath)) {
			m_pokemonModel->list()->appendItem(std::make_shared<Pokemon>(parsePokeApiJsonFile(id)));
		} else {
			QEventLoop loop;

			QNetworkAccessManager networkManager;

			QUrl url(QString("https://pokeapi.co/api/v2/pokemon/%1").arg(id));
			QNetworkRequest request(url);
			QNetworkReply* reply = networkManager.get(request);

			connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

			loop.exec();

			if (reply->error() == QNetworkReply::NoError) {
				QByteArray responseData = reply->readAll();
				QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
				if (!jsonDoc.isNull()) {
					QFile file(filePath);
					if (file.open(QIODevice::WriteOnly)) {
						file.write(jsonDoc.toJson());
						file.close();
					}
				}
			} else {
				qWarning() << "Error fetching data for Id" << id << ":" << reply->errorString();
			}

			reply->deleteLater();

			m_pokemonModel->list()->appendItem(std::make_shared<Pokemon>(parsePokeApiJsonFile(id)));
		}
	}
}

void PokeApiManager::onLoadFinished() {
	qDebug() << "Loading Pokemons completed.";
	m_pokemonModel->refreshList();
}

Pokemon PokeApiManager::parsePokeApiJsonFile(int id) {
	QString fileName = QString("%1.json").arg(id);
	QString filePath = QDir(m_pokemonInfoFolder).filePath(fileName);

	QFile pkmFile(filePath);
	if (!pkmFile.open(QIODevice::ReadOnly)) {
		qWarning() << "Cannot open file:" << fileName;
		return Pokemon();
	}

	QByteArray fileData = pkmFile.readAll();
	pkmFile.close();

	QJsonDocument document = QJsonDocument::fromJson(fileData);
	if (document.isNull()) {
		qWarning() << "Failed to parse JSON file.";
		return Pokemon();
	}

	QJsonObject pkmObject = document.object();

	Pokemon pokemon;
	pokemon.id = pkmObject["id"].toInt();
	pokemon.name = pkmObject["name"].toString();
	pokemon.baseExp = pkmObject["base_experience"].toInt();

	QJsonArray statsArray = pkmObject["stats"].toArray();
	for (const QJsonValue &value : statsArray) {
		QJsonObject statObject = value.toObject();

		int baseStat = statObject["base_stat"].toInt();
		QString statName = statObject["stat"].toObject()["name"].toString();

		if (statName == "hp") {
			pokemon.stats.hp = baseStat;
		} else if (statName == "attack") {
			pokemon.stats.attack = baseStat;
		} else if (statName == "defense") {
			pokemon.stats.defense = baseStat;
		} else if (statName == "special-attack") {
			pokemon.stats.sAttack = baseStat;
		} else if (statName == "special-defense") {
			pokemon.stats.sDefense = baseStat;
		} else if (statName == "speed") {
			pokemon.stats.speed = baseStat;
		}
	}

	pokemon.imageSvg = pkmObject["sprites"].toObject()["other"].toObject()["dream_world"].toObject()["front_default"].toString();
	pokemon.imagePng = pkmObject["sprites"].toObject()["other"].toObject()["official-artwork"].toObject()["front_default"].toString();

	printPokemonInfo(pokemon);
	return pokemon;
}

void PokeApiManager::printPokemonInfo(Pokemon pokemon) {
	qDebug() << "id: " << pokemon.id;
	qDebug() << "name: " << pokemon.name;
	qDebug() << "baseExp: " << pokemon.baseExp;
	qDebug() << "hp: " << pokemon.stats.hp;
	qDebug() << "attack: " << pokemon.stats.attack;
	qDebug() << "defense: " << pokemon.stats.defense;
	qDebug() << "sAttack: " << pokemon.stats.sAttack;
	qDebug() << "sDefense: " << pokemon.stats.sDefense;
	qDebug() << "speed: " << pokemon.stats.speed;
	qDebug() << "imageSvg: " << pokemon.imageSvg;
	qDebug() << "imagePng: " << pokemon.imagePng;
}
