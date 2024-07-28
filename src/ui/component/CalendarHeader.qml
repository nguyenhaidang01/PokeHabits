/******************************************************************************
**
** File      CalendarHeader.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	property QtObject model: null
	property QtObject controller: null

	implicitWidth: 1014
	implicitHeight: 86

	Rectangle {
		id: background

		anchors.fill: parent
		color: internal.obsidian_10
	}

	RowLayout {
		id: monthYearTitle

		anchors {
			top: parent.top
			topMargin: 6
			horizontalCenter: parent.horizontalCenter
		}

		spacing: 5

		Label {
			font {
				family: "Roboto"
				pixelSize: 14
				weight: Font.DemiBold
			}
			color: internal.etherealWhite_87

			text: model.selectedMonth
		}

		Label {
			font {
				family: "Roboto"
				pixelSize: 10
				weight: Font.DemiBold
			}
			color: internal.goldenYellow

			text: model.selectedYear
		}
	}

	ListView {
		id: calendar

		implicitWidth: 740
		implicitHeight: 48

		anchors {
			horizontalCenter: parent.horizontalCenter
			verticalCenter: parent.verticalCenter
			verticalCenterOffset: 12
		}

		clip: true
		spacing: 10
		orientation: ListView.Horizontal
		highlight: hightlight
		highlightMoveDuration: 0
		currentIndex: model.currentDateIndex

		model: root.model
		delegate: dayDelegate
	}

	Component {
		id: dayDelegate

		DayDelegate {
			listView: calendar
			controller: root.controller
		}
	}

	Component {
		id: hightlight

		Rectangle {
			implicitWidth: 40
			implicitHeight: 48

			radius: 4
			color: internal.obsidian_70
			border {
				width: 1.5
				color: internal.obsidian_40
			}
		}
	}

	QtObject {
		id: internal

		readonly property color obsidian: "#000000"
		readonly property color etherealWhite: "#FFFFFF"
		readonly property color goldenYellow: "#ebc221"
		readonly property color obsidian_10: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.1)
		readonly property color obsidian_40: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.4)
		readonly property color obsidian_70: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.7)
		readonly property color etherealWhite_87: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0.87)
	}
}
