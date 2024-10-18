/******************************************************************************
**
** File      TargetPokeDataField.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

RowLayout {
	id: root

	property string pokemonUrl: internal.defaultPokemonUrl

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

			source: root.pokemonUrl
		}

		Image {
			width: internal.editIconSize
			height: internal.editIconSize

			anchors {
				right: parent.right
				bottom: parent.bottom
			}

			source: internal.editUrl
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property int editIconSize: 40
		readonly property int pokemonSize: 150

		readonly property string defaultPokemonUrl: "qrc:/ui/assets_v2/bulbasaur.svg"
		readonly property string editUrl: "qrc:/ui/assets_v2/pen.svg"
	}
}
