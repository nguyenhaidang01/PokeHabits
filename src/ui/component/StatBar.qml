/******************************************************************************
**
** File      StatBar.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
	id: root

	property string statName
	property string statValue

	implicitWidth: 259
	implicitHeight: 24

	Item {
		Layout.fillWidth: true
		Layout.fillHeight: true
	}

	Item {
		width: 45
		Layout.fillHeight: true

		Text {
			anchors.fill: parent

			font {
				pixelSize: 12
				weight: Font.DemiBold
				family: "Poppins"
			}

			verticalAlignment: Text.AlignVCenter
			text: root.statName
		}
	}

	Item {
		width: 20
		Layout.fillHeight: true

		Text {
			anchors.fill: parent

			font {
				pixelSize: 12
				weight: Font.DemiBold
				family: "Poppins"
			}

			horizontalAlignment: Text.AlignRight
			verticalAlignment: Text.AlignVCenter

			text: root.statValue
		}
	}

	Rectangle {
		id: backgroundBar

		implicitWidth: 162
		implicitHeight: 6

		Layout.alignment: Qt.AlignHCenter
		radius: 4

		color: internal.backgroundBarColor

		Rectangle {
			id: progressBar

			implicitWidth: internal.progressBarWidth
			implicitHeight: 6

			Layout.alignment: Qt.AlignHCenter
			radius: 4

			color: internal.progressBarColor
		}
	}

	QtObject {
		id: internal

		readonly property int progressBarWidth: Math.min(backgroundBar.width * root.statValue / 100, backgroundBar.width)

		readonly property color backgroundBarColor: UiStyle.obsidian_40
		readonly property color progressBarColor: UiStyle.mintGreen
	}
}
