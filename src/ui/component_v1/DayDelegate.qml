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
		color: UiStyle.transparent
		border {
			width: 1.5
			color: isCurrentDate? UiStyle.goldenYellow : UiStyle.obsidian_40
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

				color: isSunday? UiStyle.cherryRed : UiStyle.etherealWhite_87
				text: dayOfWeek
			}

			Label {
				Layout.alignment: Qt.AlignHCenter

				font {
					family: "Roboto"
					pixelSize: 12
					weight: Font.DemiBold
				}

				color: UiStyle.etherealWhite_87
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
}
