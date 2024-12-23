/******************************************************************************
**
** File      PokemonModel.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <QAbstractListModel>
#include <QVector>

struct Pokemon;

using PokemonListPtr = std::shared_ptr<QVector<Pokemon>>;

class PokemonModel : public QAbstractListModel
{
	Q_OBJECT

public:
	explicit PokemonModel(QObject *parent = nullptr);

	enum DataRole {
		IdRole = Qt::UserRole,
		NameRole,
		ImageRole,
		BaseExpRole,
		FirstTypeRole,
		SecondTypeRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual QHash<int, QByteArray> roleNames() const override;

	PokemonListPtr list() const;
	void setList(PokemonListPtr list);

	void appendItem(Pokemon &pokemon);

private:
	PokemonListPtr m_List;
};
