/******************************************************************************
**
** File      PokedexDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property string pokemonUrl: internal.defaultPokemonUrl
	property string pokemonName: internal.defaultPokemonName

	implicitWidth: internal.defaultDelegateSize
	implicitHeight: internal.defaultDelegateSize

	ColumnLayout {
		anchors.fill: parent

		Rectangle {
			Layout.preferredWidth: internal.pokemonFrameSize
			Layout.preferredHeight: internal.pokemonFrameSize

			Layout.topMargin: 8
			Layout.alignment: Qt.AlignHCenter

			radius: internal.radius
			border.width: internal.borderWidth

			Image {
				width: internal.pokemonSize
				height: internal.pokemonSize

				anchors.centerIn: parent
				source: root.pokemonUrl
			}
		}

		Text {
			width: internal.pokemonFrameSize
			height: 32

			Layout.alignment: Qt.AlignHCenter

			font {
				pixelSize: 21
				weight: Font.Medium
				family: "Poppins"
			}

			verticalAlignment: Text.AlignVCenter
			text: root.pokemonName
		}
	}

	QtObject {
		id: internal

		readonly property int defaultDelegateSize: 240
		readonly property int pokemonFrameSize: 200
		readonly property int pokemonSize: 150

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property string defaultPokemonName: "Bulbasour"
		readonly property string defaultPokemonUrl: "qrc:/ui/assets_v2/bulbasaur.svg"
	}
}
