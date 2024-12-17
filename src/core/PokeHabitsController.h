#pragma once

#include <QMap>
#include <QDate>

#include "UiController.h"

class PokeHabitsController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(UiController* uiController READ uiController CONSTANT)

public:
	static PokeHabitsController* getInstance();

	UiController* uiController();
public slots:

signals:

private:
	explicit PokeHabitsController(QObject *parent = nullptr);

	UiController* m_uiController;
};
