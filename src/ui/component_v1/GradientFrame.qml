/******************************************************************************
**
** File      GradientFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

MouseArea {
	id: root

	implicitWidth: 120
	implicitHeight: 90

	propagateComposedEvents: true

	Rectangle {
		id: frame

		anchors.fill: parent

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
				implicitWidth: root.width
				implicitHeight: root.height
				radius: internal.radius
				border.color: UiStyle.obsidian_10
			}
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 6
	}
}
