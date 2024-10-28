#include "ViewController.h"

namespace {
const QString cContentStateName("displayHabits");
const QString cEditorStateName("editorHabit");
const QString cDetailStateName("habitDetail");
}

ViewController::ViewController(QObject *parent)
    : QObject(parent)
    , m_currentState(cContentStateName)
{
}

void ViewController::changeToContentView()
{
	m_previouState = m_currentState;
	m_currentState = cContentStateName;

	emit viewStateChanged(m_currentState);
}

void ViewController::changeToHabitEditorView()
{
	m_previouState = m_currentState;
	m_currentState = cEditorStateName;

	emit viewStateChanged(m_currentState);
}

void ViewController::changeToHabitDetailView()
{
	m_previouState = m_currentState;
	m_currentState = cDetailStateName;

	emit viewStateChanged(m_currentState);
}

void ViewController::changeToPreviousView()
{
	emit viewStateChanged(m_previouState);

	std::swap(m_currentState, m_previouState);
}
