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
	void changeToHabitDetailView();
	void changeToPreviousView();
	void changeToHabitEditorView(int habitIndex);

signals:
	void uiStateChanged(QString uiState);
	void editIndexChanged(int index);

private:
	QString m_currentState;
	QString m_previouState;
};
