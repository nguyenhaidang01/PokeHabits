#pragma once

#include <QAbstractListModel>

Q_MOC_INCLUDE("PokemonList.h")

class PokemonList;

class PokemonModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(PokemonList *pokemonList READ pokemonList WRITE setPokemonList)

public:
	explicit PokemonModel(QObject *parent = nullptr);
	explicit PokemonModel(PokemonList *pkmList, QObject *parent = nullptr);

	enum {
		sIndexRole = Qt::UserRole,
		eIndexRole,
		cIndexRole,
		NameRole,
		ImageRole,
		ExpRole,
		DoneRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;

	virtual QHash<int, QByteArray> roleNames() const override;

	PokemonList *pokemonList() const;
	void setPokemonList(PokemonList *list);

private:
	PokemonList *m_pkmList;
};
