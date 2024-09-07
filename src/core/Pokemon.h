#pragma once

#include <QList>
#include <QDate>

struct Stats {
	int hp;
	int attack;
	int defense;
	int sAttack;
	int sDefense;
	int speed;
};

struct Pokemon {
	int id;
	QString name;
	int baseExp;
	Stats stats;
	QString imageSvg;
	QString imagePng;
};

struct PokeHabit
{
	QString habitName;
	int exp;
	bool done;
	QString image;
	Pokemon pokemon;
};
