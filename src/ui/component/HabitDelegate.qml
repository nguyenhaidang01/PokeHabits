/******************************************************************************
**
** File      HabitDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
	id: root

	implicitWidth: 414
	implicitHeight: 181

	spacing: 4

	Rectangle {
		id: habitTitle

		implicitWidth: 414
		implicitHeight: 32

		color: internal.transObsidian

		Label {
			id: nameLabel

			anchors {
				verticalCenter: parent.verticalCenter
				left: parent.left
				leftMargin: 26
			}

			font {
				bold: true
				italic: true
				pixelSize: 18
				family: "Roboto"
			}
			text: name
			color: internal.etherealWhite
		}
	}

	RowLayout {
		id: habitItem

		implicitWidth: 390
		implicitHeight: 145

		Layout.alignment: Qt.AlignRight

		Item {
			id: habitRepresent

			implicitWidth: 120
			implicitHeight: 122

			Rectangle {
				id: pkmFrame

				implicitWidth: 120
				implicitHeight: 90
				anchors {
					bottom: parent.bottom
					bottomMargin: 10
				}

				radius: internal.radius
				color: internal.transObsidian
			}

			Image {
				id: pkmImage

				anchors {
					horizontalCenter: parent.horizontalCenter
					verticalCenter: parent.verticalCenter
					verticalCenterOffset: -10
				}
				source: image
			}
		}

		Rectangle {
			id: pkmInfo

			implicitWidth: 259
			implicitHeight: 145

			radius: internal.radius
			color: internal.transObsidian
		}
	}
	QtObject {
		id: internal

		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
		readonly property int radius: 6
		readonly property color ghostWhite: "#FCFCFC"
		readonly property color etherealWhite: "#FFFFFF"
		readonly property color obsidian: "#000000"
		readonly property color transObsidian: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.1)
	}
}
