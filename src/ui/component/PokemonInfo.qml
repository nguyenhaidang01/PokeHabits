/******************************************************************************
**
** File      PokemonInfo.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	property string pokeId: internal.defaultPokemonId
	property string pokeName: internal.defaultPokemonName
	property string pokeFirstType: internal.defaultPokeType
	property string pokeSecondType: UiConstant.nullstr

	ColumnLayout {
		anchors.fill: parent

		ColumnLayout {
			Layout.preferredWidth: 165
			Layout.preferredHeight: 65

			Text {
				Layout.alignment: Qt.AlignTop

				font {
					pixelSize: 32
					weight: Font.Medium
					family: "Poppins"
				}

				text: root.pokeName
			}

			Text {
				Layout.alignment: Qt.AlignBottom

				font {
					pixelSize: 16
					weight: Font.Medium
					family: "Poppins"
				}

				text: "No " + ("0000" + root.pokeId).slice(-4)
			}
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 36

			Layout.alignment: Qt.AlignBottom

			ElementFrame {
				Layout.preferredWidth: internal.elementFrameWidth
				Layout.preferredHeight: internal.elementFrameHeight

				elementName: root.pokeFirstType
			}

			ElementFrame {
				Layout.preferredWidth: internal.elementFrameWidth
				Layout.preferredHeight: internal.elementFrameHeight

				elementName: root.pokeSecondType
			}
		}
	}

	QtObject {
		id: internal

		readonly property int elementFrameWidth: 114
		readonly property int elementFrameHeight: 36

		property string defaultPokemonName: "Bulbasour"
		property string defaultPokemonId: "001"
		property string defaultPokeType: "grass"
	}
}
