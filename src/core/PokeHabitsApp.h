#pragma once

#include <QMap>
#include <QDate>

#include "ViewController.h"

class PokeHabitsApp : public QObject
{
	Q_OBJECT
	Q_PROPERTY(ViewController* viewController READ viewController CONSTANT)

public:
	static PokeHabitsApp* getInstance();

	ViewController* viewController();
public slots:

signals:

private:
	explicit PokeHabitsApp(QObject *parent = nullptr);

	ViewController* m_viewController;
};
