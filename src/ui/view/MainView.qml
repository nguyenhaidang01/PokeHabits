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
					internal.selectedHabitIndex = index;
				}
			}

			Component {
				id: habitDashboardView

				HabitDashboardView {
					model: internal.habitModel
					controller: internal.controller
					calendarModel: internal.calendarModel
				}
			}

			Component {
				id: habitEditorView

				HabitEditorView {
					model: internal.habitModel
					controller: internal.controller

					editIndex: internal.selectedHabitIndex
					pokemonModel: internal.pokemonModel
				}
			}

			Component {
				id: habitDetailView

				HabitDetailView {
					model: internal.habitModel
					controller: internal.controller
				}
			}
		}
	}

	QtObject {
		id: internal

		property int selectedHabitIndex: -1
		readonly property int sidebarWidth: 350

		property QtObject controller: pokeHabitsController
		property QtObject uiService: pokeHabitsController.uiService

		property QtObject calendarModel: pokeHabitsController.calendarModel
		property QtObject pokemonModel: pokeHabitsController.pokemonModel
		property QtObject habitModel: pokeHabitsController.habitModel
	}
}
