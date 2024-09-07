/******************************************************************************
**
** File      HabitDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

ColumnLayout {
	id: root

	implicitWidth: 414
	implicitHeight: 181

	spacing: 4

	Rectangle {
		id: habitTitle

		implicitWidth: 414
		implicitHeight: 32

		color: UiStyle.obsidian_10
		Label {
			id: nameLabel

			anchors {
				verticalCenter: parent.verticalCenter
				left: parent.left
				leftMargin: 26
			}

			font {
				bold: true
				italic: true
				pixelSize: 18
				family: "Roboto"
			}
			text: habitName
			color: UiStyle.etherealWhite
		}
	}

	RowLayout {
		id: habitItem

		implicitWidth: 390
		implicitHeight: 145

		Layout.alignment: Qt.AlignRight

		PokemonFrame {
			id: habitRepresent

			implicitWidth: 120
			implicitHeight: 142

			pokemonImg: internal.examplePokemon
			pokemonName: pkmName
		}

		Rectangle {
			id: pkmInfo

			implicitWidth: 259
			implicitHeight: 145

			radius: internal.radius
			color: UiStyle.obsidian_10
		}
	}
	QtObject {
		id: internal

		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
		readonly property int radius: 6
		readonly property url examplePokemon: "qrc:/ui/assets/Leafeon.png"
	}
}
