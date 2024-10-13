/******************************************************************************
**
** File      ProfileToolFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	ColumnLayout {
		anchors.fill: parent

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 85

			Rectangle {
				Layout.preferredWidth: internal.avatarSize
				Layout.preferredHeight: internal.avatarSize

				radius: internal.avatarSize/2
				color: internal.avatarColor

				Layout.leftMargin: 20

				Text {
					anchors.centerIn: parent
					font {
						pixelSize: 28
						family: "Inter"
					}

					color: UiConstant.pureWhite
					text: internal.userNameBrief
				}
			}

			Text {
				Layout.leftMargin: 14

				font {
					pixelSize: 21
					family: "Inter"
				}

				color: UiConstant.pureBlack
				text: internal.userName
			}
		}

		Rectangle {
			Layout.preferredWidth: 310
			Layout.preferredHeight: 40

			Layout.bottomMargin: 15
			Layout.alignment: Qt.AlignHCenter

			radius: 4
			color: UiConstant.pureWhite

			RowLayout {
				anchors.fill: parent

				Text {
					Layout.leftMargin: 14

					font {
						pixelSize: 21
						family: "Inter"
					}

					color: UiConstant.pureBlack
					text: "Search"
				}

				Item {
					Layout.fillWidth: true
					Layout.fillHeight: true
				}

				Image {
					width: internal.searchSize
					height: internal.searchSize

					Layout.rightMargin: 7

					source: "qrc:/ui/assets_v2/search.svg"
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property int searchSize: 24

		readonly property int avatarSize: 60
		readonly property color avatarColor: "#f88ce4"

		readonly property string userName: "Dang Nguyen"
		readonly property string userNameBrief: "DN"
	}
}
