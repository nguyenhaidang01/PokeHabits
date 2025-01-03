/******************************************************************************
**
** File      ElementFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Rectangle {
	id: root

	property string elementName

	visible: elementName !== UiConstant.nullstr

	implicitWidth: internal.defaultFrameWidth
	implicitHeight: internal.defaultFrameHeight

	radius: internal.radius
	color: visible ? UiConstant.typeColorMap[elementName] : UiConstant.transparent

	RowLayout {
		anchors.fill: parent

		ElementIcon {
			id: elementIcon

			Layout.leftMargin: 6
			elementName: root.elementName
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
			text: root.elementName.charAt(0).toUpperCase() + root.elementName.substring(1)
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
	}
}
