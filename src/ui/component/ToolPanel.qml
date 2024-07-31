/******************************************************************************
**
** File      ToolPanel.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	implicitWidth: 486
	implicitHeight: 117

	Rectangle {
		anchors.fill: parent

		radius: 28
		color: UiStyle.etherealWhite_11

		RowLayout {
			implicitWidth: 486

			anchors {
				horizontalCenter: parent.horizontalCenter
				verticalCenter: parent.verticalCenter
				verticalCenterOffset: -24
			}

			spacing: 40

			ToolItem {
				id: tool1

				toolName: "Tool 1"
				toolImg: "qrc:/ui/assets/Lures.png"
			}

			ToolItem {
				id: tool2

				toolName: "Tool 2"
				toolImg: "qrc:/ui/assets/EggDistance.png"
			}

			ToolItem {
				id: tool3

				toolName: "Tool 3"
				toolImg: "qrc:/ui/assets/Camera.png"
			}
		}
	}
}
