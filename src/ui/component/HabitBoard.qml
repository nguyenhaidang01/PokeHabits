/******************************************************************************
**
** File      HabitBoard.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls

Item {
	id: root

	implicitWidth: 952
	implicitHeight: 374

	property QtObject habitModel: null
	property QtObject pokemonModel: null
	property alias state: habitList.state

	signal openAddHabitPopup()

	GridView {
		id: habitList

		anchors.fill: parent

		cellWidth: internal.gridCellWidth
		cellHeight: internal.gridCellHeight

		clip: true
		delegate: gridDelegate

		AddHabitPopup {
			id: addHabitPopup

			width: 383
			height: 236
			anchors.centerIn: parent

			model: root.pokemonModel

			onOpenChoosePokemonPopup: function() {
				choosePokemonPopup.open();
				habitList.state = "choosePopupOpening";
			}

			onClosed: function() {
				habitList.state = "idle";
			}
		}

		ChoosePokemonPopup {
			id: choosePokemonPopup

			width: 464
			height: 423

			leftMargin : 275

			model: root.pokemonModel

			onClosed: function() {
				habitList.state = "addHabitPopupOpening";
			}
		}

		states: [
			State {
				name: "idle"
				PropertyChanges { target: habitList; model: root.habitModel }
				PropertyChanges { target: addHabitPopup; visible: false }
				PropertyChanges { target: choosePokemonPopup; visible: false }
			},
			State {
				name: "addHabitPopupOpening"
				PropertyChanges { target: habitList; model: null }
				PropertyChanges { target: addHabitPopup; visible: true }
				PropertyChanges { target: choosePokemonPopup; visible: false }
			},
			State {
				name: "choosePopupOpening"
				PropertyChanges { target: habitList; model: null }
				PropertyChanges { target: addHabitPopup; visible: false }
				PropertyChanges { target: choosePokemonPopup; visible: true }
			}
		]
		state: "idle"
	}

	Component {
		id: gridDelegate

		HabitDelegate {
			id: habitDelegate
		}
	}

	onOpenAddHabitPopup: function() {
		habitList.state = "addHabitPopupOpening";
		addHabitPopup.open();
	}

	QtObject {
		id: internal

		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
	}
}
