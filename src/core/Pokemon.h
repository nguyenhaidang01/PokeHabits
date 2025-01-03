/******************************************************************************
**
** File      Pokemon.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once
#include <unordered_map>
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
	Unknown,
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

namespace pokemon_util {

static const std::unordered_map<QString, Type> typeNameToEnumMap = {
    {"normal", Type::Normal},
    {"fire", Type::Fire},
    {"water", Type::Water},
    {"grass", Type::Grass},
    {"electric", Type::Electric},
    {"ice", Type::Ice},
    {"fighting", Type::Fighting},
    {"poison", Type::Poison},
    {"ground", Type::Ground},
    {"flying", Type::Flying},
    {"psychic", Type::Psychic},
    {"bug", Type::Bug},
    {"rock", Type::Rock},
    {"ghost", Type::Ghost},
    {"dragon", Type::Dragon},
    {"dark", Type::Dark},
    {"steel", Type::Steel},
    {"fairy", Type::Fairy}
};

static const std::unordered_map<Type, QString> enumToTypeNameMap = {
    {Type::Normal, "normal"},
    {Type::Fire, "fire"},
    {Type::Water, "water"},
    {Type::Grass, "grass"},
    {Type::Electric, "electric"},
    {Type::Ice, "ice"},
    {Type::Fighting, "fighting"},
    {Type::Poison, "poison"},
    {Type::Ground, "ground"},
    {Type::Flying, "flying"},
    {Type::Psychic, "psychic"},
    {Type::Bug, "bug"},
    {Type::Rock, "rock"},
    {Type::Ghost, "ghost"},
    {Type::Dragon, "dragon"},
    {Type::Dark, "dark"},
    {Type::Steel, "steel"},
    {Type::Fairy, "fairy"}
};

} // namespace pokemon_util
