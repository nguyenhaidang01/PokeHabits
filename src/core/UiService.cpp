/******************************************************************************
**
** File      UiService.cpp
** Author    Dang Nguyen
**
******************************************************************************/

#include "UiService.h"

namespace {

const QString cDashboardStateName("dashboardState");
const QString cEditStateName("editState");
const QString cDetailStateName("detailState");

}

UiService::UiService(QObject *parent)
    : QObject(parent)
    , m_currentState(cDashboardStateName)
{
}

void UiService::changeToHabitDashboardView()
{
	m_previouState = m_currentState;
	m_currentState = cDashboardStateName;

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
	m_currentState = cEditStateName;

	emit editIndexChanged(habitIndex);
	emit uiStateChanged(m_currentState);
}
