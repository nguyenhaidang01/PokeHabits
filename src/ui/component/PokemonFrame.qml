/******************************************************************************
**
** File      PokemonFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component"

Rectangle {
	id: root

	property string pokeImage
	property string pokeType

	implicitWidth: internal.frameSize
	implicitHeight: internal.frameSize

	radius: internal.frameRadius
	color: UiConstant.typeColorMap[pokeType]

	Image {
		id: element

		width: internal.elementSize
		height: internal.elementSize
		anchors.centerIn: parent

		source: UiConstant.typeImageUrlMap[pokeType]
	}

	Image {
		id: pokemon

		width: 86
		height: 86
		anchors.centerIn: parent

		source: root.pokeImage
	}

	QtObject {
		id: internal

		readonly property int frameSize: 145
		readonly property int frameRadius: 15

		readonly property int elementSize: 120
	}
}
