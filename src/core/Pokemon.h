/******************************************************************************
**
** File      Pokemon.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once
#include <QVector>

enum class Type;

struct Pokemon {
	int id;
	QString name;
	QString image;
	int baseExp;
	QVector<Type> types;
};

enum class Type {
	Normal,
	Fire,
	Water,
	Grass,
	Electric,
	Ice,
	Fighting,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock,
	Ghost,
	Dragon,
	Dark,
	Steel,
	Fairy
};
