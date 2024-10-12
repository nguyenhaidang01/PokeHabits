/******************************************************************************
**
** File      ViewV1.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v1"

ApplicationWindow  {
	id: root

	visible: true

	width: 1014
	height: 784

	title: qsTr("Pokemon Habit")

	background: Rectangle {
		color: "#58726F"
	}

	ColumnLayout {
		anchors.fill: parent

		CalendarHeader {
			id: calendar

			model: internal.calendarModel
			controller: internal.controller
		}

		NoteBoard {
			id: noteBoard
		}

		HabitBoard {
			id: habitBoard

			Layout.topMargin: 24
			Layout.leftMargin: 62

			habitModel: internal.dailyReportModel
			pokemonModel: internal.pokemonModel
			controller: internal.controller
		}

		Item {
			id: scrolldown

			visible: internal.scrolldownVisible
			implicitWidth: 130
			implicitHeight: 24
			Layout.alignment: Qt.AlignHCenter

			Image {
				width: 95
				height: 24
				anchors.right: parent.right
				source: "qrc:/ui/assets_v1/scrolldown.svg"
			}
		}

		Rectangle {
			Layout.fillHeight: true
			// TODO
		}

		ToolPanel {
			id: toolPanel

			Layout.alignment: Qt.AlignHCenter
			Layout.bottomMargin: -50

			onAddHabit: function() {
				habitBoard.openAddHabitPopup();
			}
		}
	}

	QtObject {
		id: internal

		property QtObject controller: pokeHabitsApp
		property QtObject dailyReportModel: pokeHabitsApp.dailyReportModel
		property QtObject calendarModel: pokeHabitsApp.calendarModel
		property QtObject pokemonModel: pokeHabitsApp.pokemonModel()
		property bool scrolldownVisible: habitBoard.state == "idle" && pokeHabitsApp.dailyReportModel && pokeHabitsApp.dailyReportModel.count > 4
	}
}
