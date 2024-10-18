/******************************************************************************
**
** File      TextWithPokeball.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component_v2"

Item {
	id: root

	property string text
	property int textSize: internal.defaultTextSize
	property int spacing: internal.defaultSpacing
	property int pokeballSize: internal.defaultPokeballSize

	implicitWidth: childrenRect.width
	implicitHeight: pokeballSize

	Image {
		id: pokeball

		width: root.pokeballSize
		height: root.pokeballSize

		source: internal.pokeballUrl
	}

	Text {
		height: root.pokeballSize

		anchors {
			left: pokeball.right
			leftMargin: internal.defaultSpacing
		}

		font {
			pixelSize: internal.defaultTextSize
			weight: Font.Medium
			family: "Poppins"
		}

		verticalAlignment: Text.AlignVCenter
		text: root.text
	}

	QtObject {
		id: internal

		readonly property int defaultTextSize: 21
		readonly property int defaultSpacing: 10
		readonly property int defaultPokeballSize: 35
		readonly property string pokeballUrl: "qrc:/ui/assets_v2/pokeball.svg"
	}
}
