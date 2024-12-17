#pragma once

#include <QMap>
#include <QDate>

#include "UiController.h"

class PokeHabitsApp : public QObject
{
	Q_OBJECT
	Q_PROPERTY(UiController* uiController READ uiController CONSTANT)

public:
	static PokeHabitsApp* getInstance();

	UiController* uiController();
public slots:

signals:

private:
	explicit PokeHabitsApp(QObject *parent = nullptr);

	UiController* m_uiController;
};
