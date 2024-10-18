/******************************************************************************
**
** File      HabitNameDataField.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

RowLayout {
	id: root

	property string habitName: internal.defaultHabitName

	spacing: 0

	Item {
		Layout.preferredWidth: 317
		Layout.fillHeight: true

		TextWithPokeball {
			anchors.verticalCenter: parent.verticalCenter
			text: "Habit Name"
		}
	}

	Rectangle {
		Layout.fillWidth: true
		Layout.fillHeight: true

		radius: internal.radius
		border.width: internal.borderWidth

		Text {
			anchors.fill: parent

			font {
				pixelSize: 21
				weight: Font.Medium
				family: "Poppins"
			}
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

			text: "Go Gym"
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property string defaultHabitName: "Go Gym"
	}
}
