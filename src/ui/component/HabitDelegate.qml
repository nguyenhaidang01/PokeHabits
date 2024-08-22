/******************************************************************************
**
** File      HabitDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

ColumnLayout {
	id: root

	implicitWidth: 414
	implicitHeight: 181

	spacing: 4

	Rectangle {
		id: habitTitle

		implicitWidth: 414
		implicitHeight: 32

		color: UiStyle.obsidian_10
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
			color: UiStyle.etherealWhite
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
				color: UiStyle.transparent
				border.color: UiStyle.obsidian_10

				RadialGradient {
					anchors.fill: parent

					gradient: Gradient {
						GradientStop { position: 0.34; color: UiStyle.ghostWhite_0 }
						GradientStop { position: 1; color: UiStyle.etherealWhite_12 }
					}

					source: Rectangle {
						implicitWidth: 120
						implicitHeight: 90
						radius: internal.radius
						border.color: UiStyle.obsidian_10
					}
				}
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
			color: UiStyle.obsidian_10
		}
	}
	QtObject {
		id: internal

		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
		readonly property int radius: 6
	}
}
