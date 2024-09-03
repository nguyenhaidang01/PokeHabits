#pragma once

#include <QObject>
#include <QList>

struct PokeHabit;

using ListDailyReportPtr = std::shared_ptr<QList<std::shared_ptr<PokeHabit>>>;

class DailyReportList : public QObject
{
	Q_OBJECT
public:
	explicit DailyReportList(QObject *parent = nullptr);
	explicit DailyReportList(ListDailyReportPtr list, QObject *parent = nullptr);

	ListDailyReportPtr items() const;

	bool setDailyReporItemAt(int index, std::shared_ptr<PokeHabit> item);

signals:
	void preDailyReportItemAppended();
	void postDailyReportItemAppended();

	void preDailyReportItemRemoved(int index);
	void postDailyReportItemRemoved();

public slots:
	void appendDailyReportItem(std::shared_ptr<PokeHabit> item);

private:
	ListDailyReportPtr m_list;
};
