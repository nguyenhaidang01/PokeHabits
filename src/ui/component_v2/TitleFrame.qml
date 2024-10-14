/******************************************************************************
**
** File      TitleFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property string habitName: internal.defaultHabitName

	implicitWidth: internal.defaultFrameWidth
	implicitHeight: internal.defaultFrameHeight

	Rectangle {
		id: titleFrame

		implicitWidth: parent.width - 10
		implicitHeight: parent.height

		anchors.centerIn: parent

		radius: internal.radius
		color: internal.defaultElementColor

		RowLayout {
			anchors.fill: parent

			ElementIcon {
				id: elementIcon

				Layout.leftMargin: 20

				backgroundSize: internal.elementBgSize
				elementSize: internal.elementSize
			}

			Text {
				Layout.leftMargin: 30

				font {
					pixelSize: 21
					weight: Font.Medium
					family: "Poppins"
				}

				text: root.habitName
			}

			Item {
				Layout.fillWidth: true
				Layout.fillHeight: true
			}
		}
	}

	QtObject {
		id: internal

		readonly property int defaultFrameWidth: 350// 340
		readonly property int defaultFrameHeight: 50

		readonly property int radius: 8

		readonly property int elementBgSize: 28
		readonly property int elementSize: 20

		readonly property color defaultElementColor: "#EDF6EC"
		readonly property string defaultHabitName: "Habits"
	}
}
