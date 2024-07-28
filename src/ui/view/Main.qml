/******************************************************************************
**
** File      Main.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import "component"

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

			model: internal.pokemonModel
		}

		Rectangle {
			Layout.fillHeight: true
			// TODO
		}

		ToolPanel {
			id: toolPanel

			Layout.alignment: Qt.AlignHCenter
			Layout.bottomMargin: -50
		}
	}

	QtObject {
		id: internal

		property QtObject controller: pkmController
		property QtObject pokemonModel: pkmController.pokemonModel
		property QtObject calendarModel: pkmController.getCalendarModel()
	}
}
