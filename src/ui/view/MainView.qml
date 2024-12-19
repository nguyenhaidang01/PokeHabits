/******************************************************************************
**
** File      MainView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

ApplicationWindow  {
	id: root

	visible: true

	width: internal.windowWidth
	height: internal.windowHeight

	title: qsTr("Pokemon Habit")

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

			contentViewSource: contentView
			habitEditorViewSource: habitEditorView
			habitDetailViewSource: habitDetailView

			Connections {
				target: internal.uiService

				function onUiStateChanged(uiState) {
					mainViewLoader.state = uiState;
				}
			}

			Component {
				id: contentView

				ContentView {
					controller: internal.controller
					dailyReportModel: internal.dailyReportModel
				}
			}

			Component {
				id: habitEditorView

				HabitEditorView {
					uiService: internal.uiService
					pokemonModel: internal.pokemonModel
				}
			}

			Component {
				id: habitDetailView

				HabitDetailView { uiService: internal.uiService }
			}
		}
	}

	QtObject {
		id: internal

		readonly property int windowWidth: 1280
		readonly property int windowHeight: 960

		readonly property int sidebarWidth: 350

		property QtObject controller: pokeHabitsController
		property QtObject uiService: pokeHabitsController.uiService
		property QtObject calendarModel: pokeHabitsController.calendarModel
		property QtObject dailyReportModel: pokeHabitsController.dailyReportModel
		property QtObject pokemonModel: pokeHabitsController.pokemonModel
	}
}
