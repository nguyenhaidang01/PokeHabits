/******************************************************************************
**
** File      ChoosePokemonPopup.qml
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

	width: 464
	height: 423

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

	Rectangle {
		id: title

		implicitWidth: 294
		implicitHeight: 32

		anchors {
			top: parent.top
			horizontalCenter: parent.horizontalCenter
		}

		radius: 28
		color: UiStyle.etherealWhite_11

		Text {
			anchors.fill: parent

			font {
				bold: true
				italic: true
				pixelSize: 18
				family: "Roboto"
			}

			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

			color: UiStyle.mistyAqua
			text: qsTr("Choose Pokemon")
		}

		Image {
			id: searchImg

			width: 28
			height: 28

			anchors {
				verticalCenter: parent.verticalCenter
				right: parent.right
				rightMargin: 8
			}
			source: "qrc:/ui/assets/search.svg"
		}
	}

	GridView {
		id: pokedex

		width: 378
		height: 378

		cellWidth: 126
		cellHeight: 142

		anchors {
			top: parent.top
			left: parent.left
			topMargin: 34
			leftMargin: 43
		}

		clip: true

		model: root.model
		delegate: pokeElement
		currentIndex: model.currentIndex
	}

	Component {
		id: pokeElement

		Item {
			width : 126
			height: 142

			PokemonFrame {
				anchors.centerIn: parent

				pokemonImg: internal.examplePokemon
				pokemonName: name

				MouseArea {
					anchors.fill: parent
					onClicked: function() {
						root.model.currentIndex = index
						root.close()
					}
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
	}
}
