/******************************************************************************
**
** File      UiService.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "UiService.h"

namespace {

const QString cContentStateName("displayHabits");
const QString cEditorStateName("editorHabit");
const QString cDetailStateName("habitDetail");

}

UiService::UiService(QObject *parent)
    : QObject(parent)
    , m_currentState(cContentStateName)
{
}

void UiService::changeToContentView()
{
	m_previouState = m_currentState;
	m_currentState = cContentStateName;

	emit uiStateChanged(m_currentState);
}

void UiService::changeToHabitDetailView()
{
	m_previouState = m_currentState;
	m_currentState = cDetailStateName;

	emit uiStateChanged(m_currentState);
}

void UiService::changeToPreviousView()
{
	emit uiStateChanged(m_previouState);

	std::swap(m_currentState, m_previouState);
}

void UiService::changeToHabitEditorView(int habitIndex)
{
	m_previouState = m_currentState;
	m_currentState = cEditorStateName;

	emit editIndexChanged(habitIndex);
	emit uiStateChanged(m_currentState);
}
