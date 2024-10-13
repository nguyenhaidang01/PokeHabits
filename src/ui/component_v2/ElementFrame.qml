/******************************************************************************
**
** File      ElementFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Rectangle {
	id: root

	property string elementName: internal.defaultElementName

	implicitWidth: internal.defaultFrameWidth
	implicitHeight: internal.defaultFrameHeight

	radius: internal.radius
	color: internal.elementColor

	RowLayout {
		anchors.fill: parent

		ElementIcon {
			id: elementIcon

			Layout.leftMargin: 6
		}

		Text {
			id: element

			Layout.leftMargin: 3

			font {
				pixelSize: 11
				weight: Font.Medium
				family: "Poppins"
			}

			color: UiConstant.pureBlack
			text: root.elementName
		}

		Item {
			Layout.fillWidth: true
			Layout.fillHeight: true
		}
	}

	QtObject {
		id: internal

		readonly property int defaultFrameWidth: 95
		readonly property int defaultFrameHeight: 26

		readonly property int radius: 50

		readonly property color elementColor: UiConstant.grassColor
		readonly property string defaultElementName: "Grass"
	}
}
