#pragma once

#include <QObject>
#include <QList>

struct Pokemon;

class PokemonList : public QObject
{
	Q_OBJECT
public:
	explicit PokemonList(QObject *parent = nullptr);
	explicit PokemonList(QList<Pokemon*> *list, QObject *parent = nullptr);

	QList<Pokemon*>* items() const;

	bool setPokemonItemAt(int index, Pokemon *item);

signals:
	void prePokemonItemAppended();
	void postPokemonItemAppended();

	void prePokemonItemRemoved(int index);
	void postPokemonItemRemoved();

public slots:
	void appendPokemonItem(Pokemon *item);

private:
	QList<Pokemon*> *m_list;
};
