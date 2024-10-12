/******************************************************************************
**
** File      HabitTitle.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
	id: root

	property string title
	property bool isDone

	signal switchClicked()

	implicitWidth: 414
	implicitHeight: 32

	color: UiStyle.obsidian_10

	RowLayout {
		anchors.fill: parent

		Item {
			Layout.preferredWidth: 26
			Layout.fillHeight: true
		}

		Label {
			id: nameLabel

			Layout.alignment: Qt.AlignVCenter

			font {
				bold: true
				italic: true
				pixelSize: 18
				family: "Roboto"
				strikeout: done
			}
			color: root.isDone? UiStyle.mintGreen : UiStyle.etherealWhite

			text: root.title
		}

		Item {
			Layout.fillWidth: true
			Layout.fillHeight: true
		}

		Image {
			Layout.preferredWidth: 24
			Layout.preferredHeight: 24

			Layout.alignment: Qt.AlignVCenter
			Layout.rightMargin: 5

			source: internal.switchImg

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					switchClicked();
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property url switchImg: "qrc:/ui/assets_v1/switch.svg"
	}
}
