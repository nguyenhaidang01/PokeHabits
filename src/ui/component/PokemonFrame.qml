/******************************************************************************
**
** File      PokemonFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Item {
	id: root

	implicitWidth: 120
	implicitHeight: 122

	property url pokemonImg

	Rectangle {
		id: pkmFrame

		implicitWidth: 120
		implicitHeight: 90
		anchors {
			bottom: parent.bottom
			bottomMargin: 10
		}

		radius: internal.radius
		color: UiStyle.transparent
		border.color: UiStyle.obsidian_10

		RadialGradient {
			anchors.fill: parent

			gradient: Gradient {
				GradientStop { position: 0.34; color: UiStyle.ghostWhite_0 }
				GradientStop { position: 1; color: UiStyle.etherealWhite_12 }
			}

			source: Rectangle {
				implicitWidth: 120
				implicitHeight: 90
				radius: internal.radius
				border.color: UiStyle.obsidian_10
			}
		}
	}

	Image {
		id: pkmImage

		anchors {
			horizontalCenter: parent.horizontalCenter
			verticalCenter: parent.verticalCenter
			verticalCenterOffset: -10
		}
		source: root.pokemonImg
	}

	QtObject {
		id: internal

		readonly property int radius: 6
	}
}
