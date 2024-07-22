#pragma once

#include <QObject>
#include <QList>

struct Pokemon;

using ListPokemonPtr = std::shared_ptr<QList<std::shared_ptr<Pokemon>>>;

class PokemonList : public QObject
{
	Q_OBJECT
public:
	explicit PokemonList(QObject *parent = nullptr);
	explicit PokemonList(ListPokemonPtr list, QObject *parent = nullptr);

	ListPokemonPtr items() const;

	bool setPokemonItemAt(int index, std::shared_ptr<Pokemon> item);

signals:
	void prePokemonItemAppended();
	void postPokemonItemAppended();

	void prePokemonItemRemoved(int index);
	void postPokemonItemRemoved();

public slots:
	void appendPokemonItem(std::shared_ptr<Pokemon> item);

private:
	ListPokemonPtr m_list;
};
