/******************************************************************************
**
** File      MainViewLoader.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component_v2"

Loader {
	id: root

	property Component contentViewSource
	property Component habitEditorViewSource
	property Component habitDetailViewSource

	function changeToContentView() {
		internal.previousView = state;
		state = UiConstant.displayHabitsState;
	}

	function changeToHabitEditorView() {
		internal.previousView = state;
		state = UiConstant.editorHabitState;
	}

	function changeToHabitDetailView() {
		internal.previousView = state;
		state = UiConstant.habitDetailState;
	}

	function changeToPreviousView() {
		var previousView = internal.previousView;

		internal.previousView = state;
		state = previousView;
	}

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

	QtObject {
		id: internal

		property string previousView: UiConstant.displayHabitsState
	}
}
