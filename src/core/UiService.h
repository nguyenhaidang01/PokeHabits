/******************************************************************************
**
** File      UiService.h
** Author    Dang Nguyen
**
******************************************************************************/

#pragma once
#include <QObject>

class UiService : public QObject
{
	Q_OBJECT

public:
	explicit UiService(QObject *parent = nullptr);

public slots:
	void changeToContentView();
	void changeToHabitEditorView();
	void changeToHabitDetailView();
	void changeToPreviousView();

signals:
	void uiStateChanged(QString uiState);

private:
	QString m_currentState;
	QString m_previouState;
};
