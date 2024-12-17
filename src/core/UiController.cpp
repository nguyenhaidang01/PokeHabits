#include "UiController.h"

namespace {

const QString cContentStateName("displayHabits");
const QString cEditorStateName("editorHabit");
const QString cDetailStateName("habitDetail");

}

UiController::UiController(QObject *parent)
    : QObject(parent)
    , m_currentState(cContentStateName)
{
}

void UiController::changeToContentView()
{
	m_previouState = m_currentState;
	m_currentState = cContentStateName;

	emit uiStateChanged(m_currentState);
}

void UiController::changeToHabitEditorView()
{
	m_previouState = m_currentState;
	m_currentState = cEditorStateName;

	emit uiStateChanged(m_currentState);
}

void UiController::changeToHabitDetailView()
{
	m_previouState = m_currentState;
	m_currentState = cDetailStateName;

	emit uiStateChanged(m_currentState);
}

void UiController::changeToPreviousView()
{
	emit uiStateChanged(m_previouState);

	std::swap(m_currentState, m_previouState);
}
