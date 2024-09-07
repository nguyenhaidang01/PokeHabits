#pragma once

#include <memory>
#include <QObject>
#include <QVector>
#include "Pokemon.h"

using PokemonPtr = std::shared_ptr<Pokemon>;
using QVectorPokemonPtr = std::shared_ptr<QVector<PokemonPtr>>;

class PokemonList : public QObject
{
	Q_OBJECT
public:
	explicit PokemonList(QObject *parent = nullptr);

	QVectorPokemonPtr items() const;

	bool setItemAt(int index, const PokemonPtr &item);
	bool removeItemAt(int index);

signals:
	void preItemAppended();
	void postItemAppended();

	void preItemRemoved(int index);
	void postItemRemoved();

public slots:
	void appendItem(PokemonPtr nItem);

private:
	QVectorPokemonPtr m_Items;
};
