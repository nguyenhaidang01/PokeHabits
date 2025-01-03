/******************************************************************************
**
** File      Repository.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <memory>
#include <QVector>

struct Habit;

using HabitListPtr = std::shared_ptr<QVector<Habit>>;

struct Account {
	QString user;
	QString password;
};

class Repository {

public:
	Repository(QString dbName, QString databaseFolder);

	HabitListPtr readHabitListFromDatabase(const Account& account);

	bool writeHabitListToDatabase(const Account& account, HabitListPtr habitList);

private:
	QString m_databaseFolder;
	QString databasePath;
};
