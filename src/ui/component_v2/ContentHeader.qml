/******************************************************************************
**
** File      ContentHeader.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	RowLayout {
		anchors.fill: parent

		Text {
			id: listTitle

			Layout.leftMargin: 20

			font {
				pixelSize: 32
				weight: Font.DemiBold
				family: "Inter"
			}

			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter

			text: internal.listName
		}

		DateFrame {
			id: dateFrame

			Layout.preferredWidth: 460
			Layout.fillHeight: true
			Layout.alignment: Qt.AlignHCenter
		}

		Rectangle {
			id: optionButton

			Layout.preferredWidth: 50
			Layout.preferredHeight: 40
			Layout.alignment: Qt.AlignRight

			radius: internal.radius
			color: internal.optionButtonColor

			Image {
				width: internal.optionSize
				height: internal.optionSize
				anchors.centerIn: parent
				source: "qrc:/ui/assets_v2/option.svg"
			}
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 8
		readonly property int optionSize: 26
		readonly property string listName: "Habits"
		readonly property color optionButtonColor: "#D9D9D9"
	}
}



