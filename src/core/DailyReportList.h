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
	explicit DailyReportList(QVectorDailyReportPtr list, QObject *parent = nullptr);

	QVectorDailyReportPtr items() const;

	bool setItemAt(int index, DailyReportPtr item);

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
