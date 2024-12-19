/******************************************************************************
**
** File      PokeApiService.cpp
** Author    Dang Nguyen
**
******************************************************************************/
#include "PokeApiService.h"

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

#include "Pokemon.h"

#define APIURL "https://pokeapi.co/api/v2/pokemon/%1"
#define POKEMONFOLDERNAME "/Pokemon"

namespace {

void createFolder(QString path) {
	QDir dir(path);
	if (!dir.exists()) {
		if (dir.mkpath(".")) {
			qDebug() << "Folder has been created:" << path;
		} else {
			qDebug() << "Cannot create folder:" << path;
		}
	}
}

}

PokeApiService::PokeApiService(QObject *parent)
    : QObject(parent)
    , m_pokemonInfoFolder { QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append(POKEMONFOLDERNAME) }
{
	createFolder(m_pokemonInfoFolder);
	connect(QGuiApplication::instance(), &QGuiApplication::aboutToQuit,
	        this, &PokeApiService::cancelFetchJsonFiles);
}

void PokeApiService::fetchJsonFile(int id) {
	m_future = QtConcurrent::run([this, id]() {
		QString filePath = QDir(m_pokemonInfoFolder).filePath(QString("%1.json").arg(id));

		if (QFile::exists(filePath)) {
			return;
		} else {
			QEventLoop loop;

			QNetworkAccessManager networkManager;

			QUrl url(QString(APIURL).arg(id));
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
		}
	});

	m_watcher.setFuture(m_future);

	connect(&m_watcher, &QFutureWatcher<void>::finished, this, [this, id]() {
		qDebug() << "Fetch json file completed - id: " << id;
		emit fetchJsonFileCompleted(id);
	});
}

Pokemon PokeApiService::readJsonFile(int id) {
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

	const auto svgObject = pkmObject["sprites"].toObject()["other"].toObject()["dream_world"].toObject()["front_default"];
	if (svgObject.isNull()) {
		pokemon.image = pkmObject["sprites"].toObject()["other"].toObject()["official-artwork"].toObject()["front_default"].toString();
	} else {
		pokemon.image = svgObject.toString();
	}

	return pokemon;
}

void PokeApiService::fetchJsonFilesInRange(int start, int end) {
	for (int id = start; id <= end; ++id) {
		if (m_cancelled.load()) {
			qDebug() << "Fetching cancelled.";
			break;
		}

		QString filePath = QDir(m_pokemonInfoFolder).filePath(QString("%1.json").arg(id));
		if (QFile::exists(filePath)) {
			emit jsonFileAlreadyExists(id);
			continue;
		}

		fetchJsonFile(id);
	}
}

void PokeApiService::cancelFetchJsonFiles() {
	m_cancelled.store(true);

	m_future.cancel();
	m_future.waitForFinished();
}

void PokeApiService::printPokemonInfo(Pokemon pokemon) {
	qDebug() << "id: " << pokemon.id << ", name: " << pokemon.name << ", baseExp: " << pokemon.baseExp << ", image: " << pokemon.image;
}
