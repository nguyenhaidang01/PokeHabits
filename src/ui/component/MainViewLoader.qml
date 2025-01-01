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

	property Component habitDashboardViewSource
	property Component habitEditorViewSource
	property Component habitDetailViewSource

	states: [
		State {
			name: UiConstant.dashboardState
			PropertyChanges { target: root; sourceComponent: habitDashboardViewSource }
		},
		State {
			name: UiConstant.editState
			PropertyChanges { target: root; sourceComponent: habitEditorViewSource }
		},
		State {
			name: UiConstant.detailState
			PropertyChanges { target: root; sourceComponent: habitDetailViewSource }
		}
	]

	state: UiConstant.dashboardState
}
