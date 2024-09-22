/******************************************************************************
**
** File      PokemonFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

MouseArea {
	id: root

	property url pokemonImg
	property string pokemonName
	property alias twinkle: twinkle.visible

	implicitWidth: 120
	implicitHeight: 142

	GradientFrame {
		id: pkmFrame

		implicitWidth: 120
		implicitHeight: 90
		anchors {
			bottom: parent.bottom
			bottomMargin: 30
		}
	}

	Image {
		id: pkmImage

		anchors.centerIn: parent

		scale: internal.imageScale
		source: root.pokemonImg
	}

	Image {
		id: twinkle

		visible: false

		width: 15
		height: 15

		anchors {
			top: parent.top
			right: parent.right
			rightMargin: 8
			topMargin: 30
		}

		source: internal.twinkleImg
	}

	Text {
		anchors {
			horizontalCenter: parent.horizontalCenter
			top: pkmFrame.bottom
			topMargin: 5
		}

		font {
			family: "Roboto"
			pixelSize: 12
			bold: true
		}

		text: root.pokemonName
		color: UiStyle.etherealWhite
	}

	QtObject {
		id: internal

		readonly property int radius: 6
		readonly property real imageScale: 0.35
		readonly property url twinkleImg: "qrc:/ui/assets/twinkle.png"
	}
}
