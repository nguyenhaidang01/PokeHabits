#pragma once

#include <QObject>
#include <QVector>

struct PokeHabit;

using DailyReportPtr = std::shared_ptr<PokeHabit>;
using QVectorDailyReportPtr = std::shared_ptr<QVector<DailyReportPtr>>;

class DailyReportList : public QObject
{
	Q_OBJECT
public:
	explicit DailyReportList(QObject *parent = nullptr);
	explicit DailyReportList(QVector<PokeHabit> items, QObject *parent = nullptr);
	explicit DailyReportList(QVectorDailyReportPtr items, QObject *parent = nullptr);

	QVectorDailyReportPtr items() const;
	QVector<PokeHabit> itemsClone();

	bool setItemAt(int index, DailyReportPtr item);
	void setUndoneAllItems();

signals:
	void preItemAppended();
	void postItemAppended();

	void preItemRemoved(int index);
	void postItemRemoved();

public slots:
	void appendItem(DailyReportPtr item);

private:
	QVectorDailyReportPtr m_Items;
};
