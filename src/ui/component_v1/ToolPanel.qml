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

	signal addHabit()

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
				toolImg: "qrc:/ui/assets_v1/lures.png"
			}

			ToolItem {
				id: tool2

				toolName: "Add Habit"
				toolImg: "qrc:/ui/assets_v1/incubator.png"

				MouseArea {
					anchors.fill: parent
					onClicked: addHabit()
				}
			}

			ToolItem {
				id: tool3

				toolName: "Tool 3"
				toolImg: "qrc:/ui/assets_v1/camera.png"
			}
		}
	}
}
