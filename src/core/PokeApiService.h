/******************************************************************************
**
** File      PokeApiService.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <QFutureWatcher>

class Pokemon;

class PokeApiService : public QObject {
	Q_OBJECT

public:
	explicit PokeApiService(QObject* parent = nullptr);

	void fetchJsonFile(int id);
	Pokemon readJsonFile(int id);

	void fetchJsonFilesInRange(int start, int end);
	void cancelFetchJsonFiles();

	Pokemon parsePokeApiJsonFile(int id);
	void printPokemonInfo(Pokemon pokemon);

signals:
	void fetchJsonFileCompleted(int id);
	void jsonFileAlreadyExists(int id);

private:
	QFuture<void> m_future;
	QFutureWatcher<void> m_watcher;
	std::atomic<bool> m_cancelled;

	QString m_pokemonInfoFolder;
};
