#pragma once

#include <QFutureWatcher>
#include "Pokemon.h"
#include "PokemonModel.h"

class PokeApiManager : public QObject {
	Q_OBJECT

public:
	explicit PokeApiManager(QObject* parent = nullptr);

	void initPokemonModel();
	void cancelInitPokemonModel();

	PokemonModel* pokemonModel();

	Pokemon parsePokeApiJsonFile(int id);
	void printPokemonInfo(Pokemon pokemon);

signals:
	void fetchCompleted();

private slots:
	void onLoadFinished();

private:
	void loadPokemons();

	QFuture<void> m_future;
	QFutureWatcher<void> m_watcher;
	std::atomic<bool> m_cancelled;

	PokemonModel* m_pokemonModel;

	QString m_pokemonInfoFolder;
};
