/******************************************************************************
**
** File      ToolItem.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls

Item {
	id: root

	implicitWidth: 103
	implicitHeight: 54

	property string toolName
	property string toolImg

	Rectangle {
		id: circleBackground

		implicitWidth: 54
		implicitHeight: 54

		radius: 27
		color: UiStyle.etherealWhite_20
	}

	Image {
		id: toolImg

		anchors.centerIn: circleBackground
		source: root.toolImg
	}

	Label {
		id: toolName

		anchors {
			right: parent.right
			verticalCenter: parent.verticalCenter
		}

		font {
			bold: true
			italic: true
			pixelSize: 13
			family: "Roboto"
		}
		text: root.toolName
		color: UiStyle.etherealWhite
	}
}
