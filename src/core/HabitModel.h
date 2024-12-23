/******************************************************************************
**
** File      HabitModel.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <QAbstractListModel>
#include <QVector>

struct Habit;

using HabitListPtr = std::shared_ptr<QVector<Habit>>;

class HabitModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int selectedHabitIndex READ selectedHabitIndex
	           WRITE setSelectedHabitIndex NOTIFY selectedHabitIndexChanged FINAL)

public:
	explicit HabitModel(HabitListPtr habitListPtr, QObject *parent = nullptr);
	explicit HabitModel(QObject *parent = nullptr);

	enum {
		NameRole = Qt::UserRole,
		PokeIdRole,
		PokeExpRole,
		PokeLvlRole,
		PokeHasNextFormRole,
		StartDateRole,
		StretchRole,
		LongestStretchRole,
		TargetValueRole,
		TargetUnitRole,
		FrequencyRole,
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual QHash<int, QByteArray> roleNames() const override;

	HabitListPtr list() const;
	void setList(HabitListPtr list);

	int selectedHabitIndex() const;
	void setSelectedHabitIndex(int newSelectedHabitIndex);

	void appendItem(Habit &habit);
	void replaceItem(int index, Habit &habit);

public slots:
	QVariantMap get(int index) const;

signals:
	void selectedHabitIndexChanged();

private:
	int m_selectedHabitIndex;
	HabitListPtr m_List = nullptr;
};
