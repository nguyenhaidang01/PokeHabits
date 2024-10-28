#pragma once
#include <QObject>

class ViewController : public QObject
{
	Q_OBJECT

public:
	explicit ViewController(QObject *parent = nullptr);

public slots:
	void changeToContentView();
	void changeToHabitEditorView();
	void changeToHabitDetailView();
	void changeToPreviousView();

signals:
	void viewStateChanged(QString viewState);

private:
	QString m_currentState;
	QString m_previouState;
};
