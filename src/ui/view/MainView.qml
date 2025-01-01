/******************************************************************************
**
** File      MainView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	RowLayout {
		anchors.fill: parent
		spacing: 0

		SidebarView {
			id: sidebarView

			Layout.preferredWidth: internal.sidebarWidth
			Layout.maximumWidth: internal.sidebarWidth
			Layout.fillHeight: true
		}

		MainViewLoader {
			id: mainViewLoader

			Layout.fillWidth: true
			Layout.fillHeight: true

			habitDashboardViewSource: habitDashboardView
			habitEditorViewSource: habitEditorView
			habitDetailViewSource: habitDetailView

			Connections {
				target: internal.uiService

				function onUiStateChanged(uiState) {
					mainViewLoader.state = uiState;
				}

				function onEditIndexChanged(index) {
					internal.habitIndex = index;
				}
			}

			Component {
				id: habitDashboardView

				HabitDashboardView {
					controller: internal.controller
					habitModel: internal.habitModel
				}
			}

			Component {
				id: habitEditorView

				HabitEditorView {
					pokemonModel: internal.pokemonModel
					controller: internal.controller
					editHabitIndex: internal.habitIndex
				}
			}

			Component {
				id: habitDetailView

				HabitDetailView { controller: internal.controller }
			}
		}
	}

	QtObject {
		id: internal

		property int habitIndex: -1
		readonly property int sidebarWidth: 350

		property QtObject controller: pokeHabitsController
		property QtObject uiService: pokeHabitsController.uiService

		property QtObject calendarModel: pokeHabitsController.calendarModel
		property QtObject pokemonModel: pokeHabitsController.pokemonModel
		property QtObject habitModel: pokeHabitsController.habitModel
	}
}
