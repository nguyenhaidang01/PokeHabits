#pragma once

#include <QMap>
#include <QDate>

#include "CalendarModel.h"
#include "DailyReportModel.h"

using QMapDateVectorDailyReportPtr = std::shared_ptr<QMap<QDate, QVectorDailyReportPtr>>;

class DatabaseManager : public QObject
{
	Q_OBJECT

public:
	explicit DatabaseManager(QObject *parent = nullptr);

	bool createDatabase(const QString& dbName);
	bool createTables();
	void prepareDatabase();

	QMapDateVectorDailyReportPtr readDatabase(QString username, QString password);
	bool writeDatabase(QString username, QString password, QDate date, const QVectorDailyReportPtr& pokeHabitList);

private:
	QString m_databaseFolder;
};
