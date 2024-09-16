#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>

#include "Pokemon.h"
#include "DatabaseManager.h"

#define DATABASEFOLDER "/Database"
#define DATABASENAME "pokehabits.db"

DatabaseManager::DatabaseManager(QObject *parent)
	: QObject(parent)
	, m_databaseFolder { QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append(DATABASEFOLDER) }
{
	prepareDatabase();
}

bool DatabaseManager::createDatabase(const QString& dbName) {
	QDir dir(m_databaseFolder);
	if (!dir.exists()) {
		dir.mkpath(m_databaseFolder);
	}

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

	if (!db.open()) {
		qDebug() << "Error: Could not open database:" << db.lastError().text();
		return false;
	}
	return true;
}

bool DatabaseManager::createTables() {
	QSqlQuery query;

	QString createAccountTable =
		"CREATE TABLE IF NOT EXISTS account ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"username TEXT UNIQUE, "
		"password TEXT)";

	if (!query.exec(createAccountTable)) {
		qDebug() << "Error creating account table:" << query.lastError().text();
		return false;
	}

	QString createDateTable =
		"CREATE TABLE IF NOT EXISTS habit_dates ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"account_id INTEGER, "
		"date TEXT, "
		"FOREIGN KEY(account_id) REFERENCES account(id))";

	if (!query.exec(createDateTable)) {
		qDebug() << "Error creating date table:" << query.lastError().text();
		return false;
	}

	QString createPokeHabitTable =
		"CREATE TABLE IF NOT EXISTS poke_habit ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"date_id INTEGER, "
		"habit_name TEXT, "
		"exp INTEGER, "
		"done INTEGER, "
		"pokemon_id INTEGER, "
		"FOREIGN KEY(date_id) REFERENCES habit_dates(id))";

	if (!query.exec(createPokeHabitTable)) {
		qDebug() << "Error creating poke_habit table:" << query.lastError().text();
		return false;
	}

	QString createPokemonTable =
		"CREATE TABLE IF NOT EXISTS pokemon ("
		"id INTEGER PRIMARY KEY, "
		"name TEXT, "
		"base_exp INTEGER, "
		"hp INTEGER, "
		"attack INTEGER, "
		"defense INTEGER, "
		"s_attack INTEGER, "
		"s_defense INTEGER, "
		"speed INTEGER, "
		"image_svg TEXT, "
		"image_png TEXT)";

	if (!query.exec(createPokemonTable)) {
		qDebug() << "Error creating pokemon table:" << query.lastError().text();
		return false;
	}

	return true;
}

void DatabaseManager::prepareDatabase() {
	QString databasePath = QDir(m_databaseFolder).filePath(DATABASENAME);
	if (createDatabase(databasePath) && createTables()) {
		qDebug() << "Database and tables created successfully";
	} else {
		qDebug() << "Failed to create database or tables";
	}
}

bool DatabaseManager::writeDatabase(QString username, QString password, QDate date, const QVectorDailyReportPtr& pokeHabitList) {
	QSqlQuery query;

	// Find or create account
	query.prepare("SELECT id FROM account WHERE username = :username AND password = :password");
	query.bindValue(":username", username);
	query.bindValue(":password", password);
	if (!query.exec() || !query.next()) {
		// Insert account if it doesn't exist
		query.prepare("INSERT INTO account (username, password) VALUES (:username, :password)");
		query.bindValue(":username", username);
		query.bindValue(":password", password);
		if (!query.exec()) {
			qDebug() << "Error inserting account:" << query.lastError().text();
			return false;
		}
		query.exec("SELECT last_insert_rowid()");
		query.next();
	}
	int accountId = query.value(0).toInt();

	// Find or create date entry
	query.prepare("SELECT id FROM habit_dates WHERE account_id = :account_id AND date = :date");
	query.bindValue(":account_id", accountId);
	query.bindValue(":date", date.toString("yyyy-MM-dd"));
	if (!query.exec() || !query.next()) {
		// Insert new date entry
		query.prepare("INSERT INTO habit_dates (account_id, date) VALUES (:account_id, :date)");
		query.bindValue(":account_id", accountId);
		query.bindValue(":date", date.toString("yyyy-MM-dd"));
		if (!query.exec()) {
			qDebug() << "Error inserting habit date:" << query.lastError().text();
			return false;
		}
		query.exec("SELECT last_insert_rowid()");
		query.next();
	}
	int dateId = query.value(0).toInt();

	// Remove existing PokeHabits for the date_id to replace with new ones
	query.prepare("DELETE FROM poke_habit WHERE date_id = :date_id");
	query.bindValue(":date_id", dateId);
	if (!query.exec()) {
		qDebug() << "Error deleting old PokeHabits:" << query.lastError().text();
		return false;
	}

	// Insert PokeHabits
	for (const auto& pokeHabit : *pokeHabitList) {
		query.prepare("INSERT INTO poke_habit (date_id, habit_name, exp, done, pokemon_id) "
					"VALUES (:date_id, :habit_name, :exp, :done, :pokemon_id)");
		query.bindValue(":date_id", dateId);
		query.bindValue(":habit_name", pokeHabit->habitName);
		query.bindValue(":exp", pokeHabit->exp);
		query.bindValue(":done", pokeHabit->done);

		// Insert or find Pokemon
		int pokemonId = pokeHabit->pokemon.id;
		QSqlQuery pokemonQuery;
		pokemonQuery.prepare("SELECT id FROM pokemon WHERE id = :pokemon_id");
		pokemonQuery.bindValue(":pokemon_id", pokemonId);

		if (!pokemonQuery.exec() || !pokemonQuery.next()) {
			// Insert new Pokémon if it does not exist
			pokemonQuery.prepare(
				"INSERT INTO pokemon (id, name, base_exp, hp, attack, defense, s_attack, s_defense, speed, image_svg, image_png) "
				"VALUES (:id, :name, :base_exp, :hp, :attack, :defense, :s_attack, :s_defense, :speed, :image_svg, :image_png)"
			);
			pokemonQuery.bindValue(":id", pokeHabit->pokemon.id);
			pokemonQuery.bindValue(":name", pokeHabit->pokemon.name);
			pokemonQuery.bindValue(":base_exp", pokeHabit->pokemon.baseExp);
			pokemonQuery.bindValue(":hp", pokeHabit->pokemon.stats.hp);
			pokemonQuery.bindValue(":attack", pokeHabit->pokemon.stats.attack);
			pokemonQuery.bindValue(":defense", pokeHabit->pokemon.stats.defense);
			pokemonQuery.bindValue(":s_attack", pokeHabit->pokemon.stats.sAttack);
			pokemonQuery.bindValue(":s_defense", pokeHabit->pokemon.stats.sDefense);
			pokemonQuery.bindValue(":speed", pokeHabit->pokemon.stats.speed);
			pokemonQuery.bindValue(":image_svg", pokeHabit->pokemon.imageSvg);
			pokemonQuery.bindValue(":image_png", pokeHabit->pokemon.imagePng);

			if (!pokemonQuery.exec()) {
				qDebug() << "Error inserting new Pokémon:" << pokemonQuery.lastError().text();
				return false;
			}
		}

		// Insert PokeHabit with Pokemon ID
		query.bindValue(":pokemon_id", pokemonId);
		if (!query.exec()) {
			qDebug() << "Error inserting PokeHabit:" << query.lastError().text();
			return false;
		}
	}
	return true;
}

QMapDateVectorDailyReportPtr DatabaseManager::readDatabase(QString username, QString password) {
	auto habitsMap = std::make_shared<QMap<QDate, QVectorDailyReportPtr>>();

	QSqlQuery query;

	// Verify account
	query.prepare("SELECT id FROM account WHERE username = :username AND password = :password");
	query.bindValue(":username", username);
	query.bindValue(":password", password);
	if (!query.exec() || !query.next()) {
		qDebug() << "Error: Invalid account credentials.";
		return nullptr;
	}
	int accountId = query.value(0).toInt();

	// Get all habit dates for the account
	query.prepare("SELECT id, date FROM habit_dates WHERE account_id = :account_id");
	query.bindValue(":account_id", accountId);
	if (!query.exec()) {
		qDebug() << "Error fetching habit_dates:" << query.lastError().text();
		return nullptr;
	}

	// Iterate through each date and fetch the corresponding habits
	while (query.next()) {
		int dateId = query.value(0).toInt();
		QDate habitDate = QDate::fromString(query.value(1).toString(), "yyyy-MM-dd");

		// Create a new QVectorDailyReportPtr for the date
		QVectorDailyReportPtr qVectorDailyReportPtr = std::make_shared<QVector<DailyReportPtr>>();

		// Fetch all PokeHabits for the given date_id
		QSqlQuery habitQuery;
		habitQuery.prepare("SELECT habit_name, exp, done, pokemon_id FROM poke_habit WHERE date_id = :date_id");
		habitQuery.bindValue(":date_id", dateId);
		if (!habitQuery.exec()) {
			qDebug() << "Error fetching poke_habits for date_id " << dateId << ": " << habitQuery.lastError().text();
			continue;
		}

		while (habitQuery.next()) {
			DailyReportPtr dailyReportPtr = std::make_shared<PokeHabit>();
			dailyReportPtr->habitName = habitQuery.value("habit_name").toString();
			dailyReportPtr->exp = habitQuery.value("exp").toInt();
			dailyReportPtr->done = habitQuery.value("done").toBool();

			int pokemonId = habitQuery.value("pokemon_id").toInt();
			QSqlQuery pokemonQuery;
			pokemonQuery.prepare("SELECT * FROM pokemon WHERE id = :pokemon_id");
			pokemonQuery.bindValue(":pokemon_id", pokemonId);

			if (pokemonQuery.exec() && pokemonQuery.next()) {
				Pokemon pokemon;
				pokemon.id = pokemonQuery.value("id").toInt();
				pokemon.name = pokemonQuery.value("name").toString();
				pokemon.baseExp = pokemonQuery.value("base_exp").toInt();
				pokemon.stats.hp = pokemonQuery.value("hp").toInt();
				pokemon.stats.attack = pokemonQuery.value("attack").toInt();
				pokemon.stats.defense = pokemonQuery.value("defense").toInt();
				pokemon.stats.sAttack = pokemonQuery.value("s_attack").toInt();
				pokemon.stats.sDefense = pokemonQuery.value("s_defense").toInt();
				pokemon.stats.speed = pokemonQuery.value("speed").toInt();
				pokemon.imageSvg = pokemonQuery.value("image_svg").toString();
				pokemon.imagePng = pokemonQuery.value("image_png").toString();

				dailyReportPtr->pokemon = pokemon;
			}

			qVectorDailyReportPtr->append(dailyReportPtr);
		}

		// Add the habits for this date to the map
		habitsMap->insert(habitDate, qVectorDailyReportPtr);
	}

	return habitsMap;
}
