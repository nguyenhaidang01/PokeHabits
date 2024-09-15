#pragma once

#include <QAbstractListModel>
#include "PokemonList.h"

using PokemonListPtr = std::shared_ptr<PokemonList>;

class PokemonModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged FINAL)
	Q_PROPERTY(QString currentItemName READ currentItemName NOTIFY currentIndexChanged FINAL)
	Q_PROPERTY(QString currentItemImg READ currentItemImg NOTIFY currentIndexChanged FINAL)

public:
	explicit PokemonModel(QObject *parent = nullptr);

	enum {
		IdRole = Qt::UserRole,
		NameRole,
		BaseExpRole,
		HpStatRole,
		AttackRole,
		DefenseRole,
		SAttackRole,
		SDefenseRole,
		SpeedRole,
		ImageSvgRole,
		ImagePngRole
	};

	// Basic functionality:
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	// Editable:
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

	Qt::ItemFlags flags(const QModelIndex& index) const override;

	virtual QHash<int, QByteArray> roleNames() const override;

	PokemonListPtr list() const;

	void setList(PokemonListPtr list);

	void refreshList();

	int currentIndex();

	void setCurrentIndex(int nCurrentIndex);

	QString currentItemName();

	QString currentItemImg();

signals:
	void currentIndexChanged();

private:
	int m_currentIndex;
	PokemonListPtr m_List;
};
