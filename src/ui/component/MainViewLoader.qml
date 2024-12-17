/******************************************************************************
**
** File      MainViewLoader.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component"

Loader {
	id: root

	property Component contentViewSource
	property Component habitEditorViewSource
	property Component habitDetailViewSource

	states: [
		State {
			name: UiConstant.displayHabitsState
			PropertyChanges { target: root; sourceComponent: contentViewSource }
		},
		State {
			name: UiConstant.editorHabitState
			PropertyChanges { target: root; sourceComponent: habitEditorViewSource }
		},
		State {
			name: UiConstant.habitDetailState
			PropertyChanges { target: root; sourceComponent: habitDetailViewSource }
		}
	]

	state: UiConstant.displayHabitsState
}
