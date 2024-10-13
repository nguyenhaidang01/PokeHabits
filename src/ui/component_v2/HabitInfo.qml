/******************************************************************************
**
** File      HabitInfo.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property string habitName: internal.defaultHabitName
	property string pokemonName: internal.defaultPokemonName

	implicitWidth: 275
	implicitHeight: 115

	ColumnLayout {
		anchors.fill: parent

		Text {
			id: pokemonName

			font {
				pixelSize: 12
				weight: Font.DemiBold
				family: "Poppins"
			}

			text: root.pokemonName
		}

		Text {
			id: habitName

			font {
				pixelSize: 21
				weight: Font.DemiBold
				family: "Poppins"
			}

			text: root.habitName
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 16

			Text {
				font {
					pixelSize: 10
					weight: Font.Bold
					family: "Poppins"
				}

				text: "EXP"
				color: "#74CB48"
			}

			Text {
				id: exp

				font {
					pixelSize: 10
					weight: Font.Bold
					family: "Poppins"
				}

				text: "999/999"
				color: "#1D1D1D"
			}

			Rectangle {
				Layout.preferredWidth: 200
				Layout.preferredHeight: 7

				Layout.alignment: Qt.AlignRight

				radius: 4
				border.width: 0.5

				color: UiConstant.pureWhite

				Rectangle {
					width: parent.width/2
					height: parent.height

					radius: 4
					border.width: 0.5

					color: "#74CB48"
				}
			}
		}

		ListView {
			id: elementListView

			Layout.preferredWidth: 210
			Layout.preferredHeight: 26

			orientation: ListView.Horizontal
			spacing: 20

			model: 2
			delegate: ElementFrame {}
		}
	}

	QtObject {
		id: internal

		readonly property string defaultPokemonName: "Bulbasaur"
		readonly property string defaultHabitName: "Go Gym"
	}
}
