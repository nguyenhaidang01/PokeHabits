/******************************************************************************
**
** File      PokemonDataField.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

RowLayout {
	id: root

	property QtObject controller: null
	property Popup pokedexPopup: null
	property int pokeId: internal.defaultPokeId

	Layout.alignment: Qt.AlignLeft
	spacing: 0

	Item {
		Layout.preferredWidth: 317
		Layout.fillHeight: true

		TextWithPokeball {
			anchors.verticalCenter: parent.verticalCenter
			text: "POKEMON"
		}
	}

	Rectangle {
		Layout.fillWidth: true
		Layout.fillHeight: true

		radius: internal.radius
		border.width: internal.borderWidth

		Image {
			width: internal.pokemonSize
			height: internal.pokemonSize
			anchors.centerIn: parent

			source: internal.pokemonHelper.image(root.pokeId)
		}

		Image {
			width: internal.editIconSize
			height: internal.editIconSize

			anchors {
				right: parent.right
				bottom: parent.bottom
			}

			source: internal.editUrl

			MouseArea {
				anchors.fill: parent
				propagateComposedEvents: true
				onClicked: function() {
					pokedexPopup.open();
				}
			}
		}
	}

	QtObject {
		id: internal

		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property int editIconSize: 40
		readonly property int pokemonSize: 150

		readonly property int defaultPokeId: 1 // Bulbasaur Id
		readonly property string editUrl: "qrc:/ui/assets/pen.svg"
	}
}
