#pragma once

#include <QAbstractListModel>
#include "DailyReportList.h"

using DailyReportListPtr = std::shared_ptr<DailyReportList>;

class DailyReportModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int count READ count NOTIFY countChanged FINAL)

public:
	explicit DailyReportModel(QObject *parent = nullptr);
	explicit DailyReportModel(DailyReportListPtr dailyReportList, QObject *parent = nullptr);

	enum {
		HabitNameRole = Qt::UserRole,
		ExpRole,
		DoneRole,
		PokemonIdRole,
		PokemonNameRole,
		PokemonBaseExpRole,
		PokemonHpStatRole,
		PokemonAttackRole,
		PokemonDefenseRole,
		PokemonSAttackRole,
		PokemonSDefenseRole,
		PokemonSpeedRole,
		PokemonImageSvgRole,
		PokemonImagePngRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;

	virtual QHash<int, QByteArray> roleNames() const override;

	DailyReportListPtr list() const;

	void setList(DailyReportListPtr list);

	int count();

signals:
	void countChanged();

private:
	DailyReportListPtr m_List;
};
