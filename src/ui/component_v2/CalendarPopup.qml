/******************************************************************************
**
** File      CalendarPopup.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Popup {
	id: root

	implicitWidth: internal.defaultWidth
	implicitHeight: internal.defaultHeight

	modal: true
	focus: true

	background: Rectangle { radius: 36; color: internal.backgroundColor }

	ColumnLayout {
		anchors.fill: parent

		DateFrame {
			id: dateFrame

			Layout.preferredWidth: 460
			Layout.preferredHeight: 60

			Layout.alignment: Qt.AlignHCenter
		}

		ColumnLayout {
			id: calendar

			Layout.preferredWidth: 469
			Layout.preferredHeight: 432

			Layout.alignment: Qt.AlignHCenter

			spacing: 0

			ListView {
				id: dayOfWeek

				Layout.preferredWidth: 469
				Layout.preferredHeight: 30

				interactive: false

				spacing: 0
				orientation: ListView.Horizontal

				model: dayOfWeekModel

				delegate: dayOfWeekDelegate
			}

			GridView {
				id: dateList

				Layout.preferredWidth: 469
				Layout.preferredHeight: 390

				cellWidth: internal.delegateWidth
				cellHeight: internal.dateDelegateHeight

				clip: true
				model: 42

				delegate: dateDelegate
				highlight: dateHighlight
			}
		}
	}

	ListModel {
		id: dayOfWeekModel

		ListElement { day: "Sun" }
		ListElement { day: "Mon" }
		ListElement { day: "Tue" }
		ListElement { day: "Wed" }
		ListElement { day: "Thur" }
		ListElement { day: "Fri" }
		ListElement { day: "Sat" }
	}

	Component {
		id: dayOfWeekDelegate

		Item {
			implicitWidth: internal.delegateWidth
			implicitHeight: internal.dowDelegateHeight

			Text {
				id: listTitle

				anchors.fill: parent

				font {
					pixelSize: 21
					weight: Font.DemiBold
					family: "Inter"
				}

				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter

				color: internal.dowTextColor
				text: day
			}
		}
	}

	Component {
		id: dateDelegate

		Item {
			implicitWidth: internal.delegateWidth
			implicitHeight: internal.dateDelegateHeight

			Text {
				width: internal.delegateWidth
				height: internal.dateDelegateHeight - internal.gridViewSpacing

				anchors.bottom: parent.bottom

				font {
					pixelSize: 24
					weight: Font.Medium
					family: "Inter"
				}

				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter

				color: (dateList.currentIndex == index) ? UiConstant.pureWhite : UiConstant.pureBlack
				text: "31"

				MouseArea {
					anchors.fill: parent
					onClicked: function() {
						dateList.currentIndex = index;
					}
				}
			}
		}
	}

	Component {
		id: dateHighlight

		Item {
			implicitWidth: internal.delegateWidth
			implicitHeight: internal.dateDelegateHeight

			Rectangle {
				width: internal.delegateWidth
				height: internal.dateDelegateHeight - internal.gridViewSpacing

				anchors.bottom: parent.bottom

				radius: 15
				color: internal.highlightColor
			}
		}
	}

	QtObject {
		id: internal

		readonly property int defaultWidth: 518
		readonly property int defaultHeight: 535

		readonly property int gridViewSpacing: 5

		readonly property int delegateWidth: 67
		readonly property int dowDelegateHeight: 30
		readonly property int dateDelegateHeight: 65

		readonly property color dowTextColor: "#ABABAB"
		readonly property color highlightColor: "#2280EF"
		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
