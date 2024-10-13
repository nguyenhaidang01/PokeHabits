/******************************************************************************
**
** File      DateFrame.qml
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

		Image {
			id: leftDirection

			width: internal.iconSize
			height: internal.iconSize
			source: "qrc:/ui/assets_v2/leftdirection.svg"
		}

		Text {
			Layout.fillWidth: true
			Layout.fillHeight: true

			font {
				pixelSize: 32
				weight: Font.DemiBold
				family: "Inter"
			}

			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter

			text: internal.date
		}

		Image {
			id: rightDirection

			width: internal.iconSize
			height: internal.iconSize
			source: "qrc:/ui/assets_v2/rightdirection.svg"
		}
	}

	QtObject {
		id: internal

		readonly property int iconSize: 60
		readonly property string date: "October 10, 2024"
	}
}
