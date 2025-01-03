/******************************************************************************
**
** File      Repository.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "Repository.h"

#include <memory>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

#include "Habit.h"

namespace util {

void createDatabaseFolder(const QString &databaseFolder) {
	QDir dir(databaseFolder);
	if (!dir.exists()) {
		dir.mkpath(databaseFolder);
	}
}

} // namespace util

Repository::Repository(QString dbName, QString databaseFolder)
    : m_databaseFolder(databaseFolder)
    , databasePath(QDir(m_databaseFolder).filePath(dbName))
{
	util::createDatabaseFolder(databaseFolder);
}

HabitListPtr Repository::readHabitListFromDatabase(const Account& account) {
	auto habitList = std::make_shared<QVector<Habit>>();

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(databasePath);

	if (!db.open()) {
		qDebug() << "Failed to open database:" << db.lastError().text();
		return nullptr;
	}

	QSqlQuery query(db);

	query.prepare("SELECT password FROM account WHERE user = :user");
	query.bindValue(":user", account.user);

	if (!query.exec() || !query.next()) {
		qDebug() << "User not found in account table.";
		return nullptr;
	}

	QString storedPassword = query.value(0).toString();
	if (storedPassword != account.password) {
		qDebug() << "Password mismatch.";
		return nullptr;
	}

	query.prepare("SELECT pokeId, name, dates, startDate, stretch, longestStretch, targetUnit, targetValue, frequency, exp, lvl, hasNextForm "
	              "FROM habits WHERE user = :user");
	query.bindValue(":user", account.user);

	if (!query.exec()) {
		qDebug() << "Failed to execute query:" << query.lastError().text();
		return nullptr;
	}

	while (query.next()) {
		Habit habit;
		habit.pokeId = query.value(0).toInt();
		habit.name = query.value(1).toString();

		QStringList dateStrings = query.value(2).toString().split(",");
		for (const QString& dateString : dateStrings) {
			habit.dates.append(QDate::fromString(dateString, Qt::ISODate));
		}

		habit.statistics.startDate = QDate::fromString(query.value(3).toString(), Qt::ISODate);
		habit.statistics.stretch = query.value(4).toInt();
		habit.statistics.longestStretch = query.value(5).toInt();
		habit.statistics.targetUnit = query.value(6).toString();
		habit.statistics.targetValue = query.value(7).toInt();

		QStringList freqStrings = query.value(8).toString().split(",");
		for (const QString& freqString : freqStrings) {
			habit.statistics.frequency.append(static_cast<DateOfWeek>(freqString.toInt()));
		}

		habit.evolState.exp = query.value(9).toInt();
		habit.evolState.lvl = query.value(10).toInt();
		habit.evolState.hasNextForm = query.value(11).toBool();

		habitList->append(habit);
	}

	db.close();
	return habitList;
}

bool Repository::writeHabitListToDatabase(const Account& account, std::shared_ptr<QVector<Habit>> habitList) {
	QSqlDatabase db;
	if (QSqlDatabase::contains("qt_sql_default_connection")) {
		db = QSqlDatabase::database("qt_sql_default_connection");
	} else {
		util::createDatabaseFolder(m_databaseFolder);
		db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName(databasePath);
	}

	if (!db.open()) {
		qDebug() << "Failed to open database:" << db.lastError().text();
		return false;
	}

	QSqlQuery createAccountTableQuery(db);
	if (!createAccountTableQuery.exec("CREATE TABLE IF NOT EXISTS account ("
	                                  "user TEXT PRIMARY KEY, "
	                                  "password TEXT)")) {
		qDebug() << "Failed to create account table:" << createAccountTableQuery.lastError().text();
		return false;
	}

	QSqlQuery createHabitsTableQuery(db);
	if (!createHabitsTableQuery.exec("CREATE TABLE IF NOT EXISTS habits ("
	                                 "user TEXT, "
	                                 "pokeId INTEGER, "
	                                 "name TEXT, "
	                                 "dates TEXT, "
	                                 "startDate TEXT, "
	                                 "stretch INTEGER, "
	                                 "longestStretch INTEGER, "
	                                 "targetUnit TEXT, "
	                                 "targetValue INTEGER, "
	                                 "frequency TEXT, "
	                                 "exp INTEGER, "
	                                 "lvl INTEGER, "
	                                 "hasNextForm INTEGER, "
	                                 "FOREIGN KEY(user) REFERENCES account(user))")) {
		qDebug() << "Failed to create habits table:" << createHabitsTableQuery.lastError().text();
		return false;
	}

	QSqlQuery query(db);

	query.prepare("SELECT COUNT(*) FROM account WHERE user = :user");
	query.bindValue(":user", account.user);

	if (!query.exec()) {
		qDebug() << "Failed to check account existence:" << query.lastError().text();
		return false;
	}

	query.next();
	int count = query.value(0).toInt();

	if (count == 0) {
		query.prepare("INSERT INTO account (user, password) VALUES (:user, :password)");
	} else {
		query.prepare("UPDATE account SET password = :password WHERE user = :user");
	}

	query.bindValue(":user", account.user);
	query.bindValue(":password", account.password);

	if (!query.exec()) {
		qDebug() << "Failed to insert/update account:" << query.lastError().text();
		return false;
	}

	query.prepare("DELETE FROM habits WHERE user = :user");
	query.bindValue(":user", account.user);

	if (!query.exec()) {
		qDebug() << "Failed to clear old habits:" << query.lastError().text();
		return false;
	}

	query.prepare("INSERT INTO habits (user, pokeId, name, dates, startDate, stretch, longestStretch, targetUnit, targetValue, frequency, exp, lvl, hasNextForm) "
	              "VALUES (:user, :pokeId, :name, :dates, :startDate, :stretch, :longestStretch, :targetUnit, :targetValue, :frequency, :exp, :lvl, :hasNextForm)");

	for (const Habit& habit : *habitList) {
		query.bindValue(":user", account.user);
		query.bindValue(":pokeId", habit.pokeId);
		query.bindValue(":name", habit.name);

		QStringList dateStrings;
		for (const QDate& date : habit.dates) {
			dateStrings.append(date.toString(Qt::ISODate));
		}
		query.bindValue(":dates", dateStrings.join(","));

		query.bindValue(":startDate", habit.statistics.startDate.toString(Qt::ISODate));
		query.bindValue(":stretch", habit.statistics.stretch);
		query.bindValue(":longestStretch", habit.statistics.longestStretch);
		query.bindValue(":targetUnit", habit.statistics.targetUnit);
		query.bindValue(":targetValue", habit.statistics.targetValue);

		QStringList freqStrings;
		for (DateOfWeek day : habit.statistics.frequency) {
			freqStrings.append(QString::number(static_cast<int>(day)));
		}
		query.bindValue(":frequency", freqStrings.join(","));

		query.bindValue(":exp", habit.evolState.exp);
		query.bindValue(":lvl", habit.evolState.lvl);
		query.bindValue(":hasNextForm", habit.evolState.hasNextForm);

		if (!query.exec()) {
			qDebug() << "Failed to insert habit:" << query.lastError().text();
			return false;
		}
	}

	db.close();
	return true;
}
