/******************************************************************************
**
** File      PokemonFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component_v2"

Rectangle {
	id: root

	implicitWidth: internal.frameSize
	implicitHeight: internal.frameSize

	radius: internal.frameRadius
	color: UiConstant.grassColor

	Image {
		id: element

		width: internal.elementSize
		height: internal.elementSize
		anchors.centerIn: parent

		source: internal.elementUrl
	}

	Image {
		id: pokemon

		width: 86
		height: 86
		anchors.centerIn: parent

		source: internal.pokemonUrl
	}

	QtObject {
		id: internal

		readonly property int frameSize: 145
		readonly property int frameRadius: 15

		readonly property int elementSize: 120
		readonly property string elementUrl: "qrc:/ui/assets_v2/grass.svg"
		readonly property string pokemonUrl: "qrc:/ui/assets_v2/bulbasaur.svg"
	}
}
