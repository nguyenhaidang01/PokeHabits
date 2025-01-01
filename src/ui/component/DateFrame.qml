/******************************************************************************
**
** File      DateFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	property string date

	RowLayout {
		anchors.fill: parent

		Image {
			id: leftDirection

			width: internal.iconSize
			height: internal.iconSize
			source: "qrc:/ui/assets/leftdirection.svg"
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

			text: root.date
		}

		Image {
			id: rightDirection

			width: internal.iconSize
			height: internal.iconSize
			source: "qrc:/ui/assets/rightdirection.svg"
		}
	}

	QtObject {
		id: internal

		readonly property int iconSize: 60
	}
}
