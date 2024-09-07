/******************************************************************************
**
** File      AddHabitPopup.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

Popup {
	id: root

	property QtObject model: null
	signal openChoosePokemonPopup()

	width: 383
	height: 236

	dim: false
	focus: true
	modal: true

	Image {
		id: closePopup

		width: 34
		height: 34
		anchors {
			verticalCenter: parent.top
			horizontalCenter: parent.right
			horizontalCenterOffset: 5
		}
		source: "qrc:/ui/assets/MaxRevive.png"

		MouseArea {
			anchors.fill: parent
			onClicked: root.close()
		}
	}

	Item {
		width: 260
		height: 174
		anchors.centerIn: parent

		RowLayout {
			width: 260
			height: 32

			Text {
				font {
					bold: true
					italic: true
					pixelSize: 18
					family: "Roboto"
				}
				color: UiStyle.etherealWhite
				text: qsTr("Habit Name")
			}

			Item {
				Layout.fillWidth: true
				Layout.fillHeight: true
			}

			Rectangle {
				implicitWidth: 120
				implicitHeight: 32
				radius: 6
				color: UiStyle.mysticOcean
			}
		}

		RowLayout {
			width: 260
			height: 142
			anchors.bottom: parent.bottom

			Text {
				font {
					bold: true
					italic: true
					pixelSize: 18
					family: "Roboto"
				}
				color: UiStyle.etherealWhite
				text: qsTr("Pokemon")
			}

			Item {
				Layout.fillWidth: true
				Layout.fillHeight: true
			}

			PokemonFrame {
				id: pokemonFrame

				implicitWidth: 120
				implicitHeight: 142

				pokemonImg: internal.examplePokemon
				pokemonName: root.model.currentItemName

				MouseArea {
					anchors.fill: parent
					onClicked: openChoosePokemonPopup()
				}
			}
		}
	}

	background: Rectangle {
		radius: 12
		color: UiStyle.obsidian_10
		border.color: UiStyle.mysticOcean
	}

	QtObject {
		id: internal

		readonly property url examplePokemon: "qrc:/ui/assets/Leafeon.png"
		readonly property string pokemonName: "Leafeon"
	}
}
