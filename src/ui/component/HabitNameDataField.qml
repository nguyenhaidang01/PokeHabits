/******************************************************************************
**
** File      HabitNameDataField.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

import "../component"

RowLayout {
	id: root

	property alias habitName: habitNameField.text

	spacing: 0

	Item {
		Layout.preferredWidth: 317
		Layout.fillHeight: true

		TextWithPokeball {
			anchors.verticalCenter: parent.verticalCenter
			text: "HABIT NAME"
		}
	}

	Rectangle {
		Layout.fillWidth: true
		Layout.fillHeight: true

		radius: internal.radius
		border.width: internal.borderWidth

		TextField {
			id: habitNameField

			anchors.fill: parent
			font {
				pixelSize: 21
				weight: Font.Medium
				family: "Poppins"
			}

			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

			background: Rectangle {
				color: UiConstant.transparent
			}
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property real borderWidth: 0.5
	}
}
