/******************************************************************************
**
** File      Habit.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once

#include <QVector>
#include <QDate>

enum class DateOfWeek {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

struct Statistics {
	QDate startDate;
	int stretch;
	int longestStretch;
	QString targetUnit;
	int targetValue;
	QVector<DateOfWeek> frequency;
};

struct EvolState {
	int exp;
	int lvl;
	bool hasNextForm = true;
};

struct Habit {
	int pokeId;
	QString name;
	QVector<QDate> dates;
	Statistics statistics;
	EvolState evolState;
};
