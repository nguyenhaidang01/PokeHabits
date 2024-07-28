/******************************************************************************
**
** File      DayDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	property ListView listView: null
	property QtObject controller: null

	implicitWidth: 40
	implicitHeight: 48

	Rectangle {
		anchors.fill: parent

		radius: 4
		color: internal.transparent
		border {
			width: 1.5
			color: isCurrentDate? internal.goldenYellow : internal.obsidian_40
		}

		ColumnLayout {
			anchors.centerIn: parent

			Label {
				Layout.alignment: Qt.AlignHCenter

				font {
					family: "Roboto"
					pixelSize: 12
					weight: Font.DemiBold
				}

				color: isSunday? internal.cherryRed : internal.etherealWhite_87
				text: dayOfWeek
			}

			Label {
				Layout.alignment: Qt.AlignHCenter

				font {
					family: "Roboto"
					pixelSize: 12
					weight: Font.DemiBold
				}

				color: internal.etherealWhite_87
				text: day
			}
		}

		MouseArea {
			anchors.fill: parent
			onClicked: function() {
				listView.currentIndex = index
				root.controller.setSelectedDate(day, numericMonth, year);
			}
		}
	}

	QtObject {
		id: internal

		readonly property color transparent: "transparent"
		readonly property color obsidian: "#000000"
		readonly property color etherealWhite: "#FFFFFF"

		readonly property color cherryRed: "#FF4949"
		readonly property color goldenYellow: "#ebc221"
		readonly property color obsidian_40: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.4)
		readonly property color etherealWhite_87: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0.87)
	}
}
