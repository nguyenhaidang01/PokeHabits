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
	property QtObject controller: null
	signal openChoosePokemonPopup()

	width: 383
	height: 256

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
		source: "qrc:/ui/assets/maxrevive.png"

		MouseArea {
			anchors.fill: parent
			onClicked: root.close()
		}
	}

	ColumnLayout {
		width: 260
		height: 204

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

				TextField {
					id: habitNameField

					anchors.fill: parent

					font {
						bold: true
						pixelSize: 18
						family: "Roboto"
					}
					color: UiStyle.etherealWhite
					verticalAlignment: Text.AlignVCenter

					background: Rectangle {
						color: UiStyle.transparent
					}
				}
			}
		}

		RowLayout {
			width: 260
			height: 142

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

				pokemonImg: root.model.currentItemImg
				pokemonName: root.model.currentItemName

				MouseArea {
					anchors.fill: parent
					onClicked: openChoosePokemonPopup()
				}
			}
		}

		Rectangle {
			implicitWidth: 80
			implicitHeight: 30

			Layout.alignment: Qt.AlignHCenter

			radius: 6
			color: UiStyle.etherealWhite_11

			Text {
				anchors.fill: parent

				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter

				font {
					bold: true
					pixelSize: 12
					family: "Roboto"
				}
				color: UiStyle.etherealWhite
				text: "Add Habit"
			}

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					root.controller.addPokeHabit(habitNameField.text);
					root.close();
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

		readonly property url examplePokemon: "qrc:/ui/assets/leafeon.png"
		readonly property string pokemonName: "Leafeon"
	}
}
