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
	property int statValue
	property int statValueMax

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

			text: internal.valueText
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

		readonly property bool isDefaultValueMax: !root.statValueMax
		readonly property int valueMax: internal.isDefaultValueMax? 100 : root.statValueMax
		readonly property string valueText: internal.isDefaultValueMax? root.statValue : (root.statValue + "/" + root.statValueMax)

		readonly property int progressBarWidth: Math.min(backgroundBar.width * root.statValue / internal.valueMax, backgroundBar.width)
		readonly property color backgroundBarColor: UiStyle.obsidian_40
		readonly property color progressBarColor: UiStyle.mintGreen
	}
}
