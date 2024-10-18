/******************************************************************************
**
** File      PokeballDateDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	implicitWidth: internal.defaultWidth
	implicitHeight: internal.defaultHeight

	property string dayOfWeek: internal.defaultDayOfWeek

	ColumnLayout {
		anchors.fill: parent

		spacing: 0

		Image {
			width: internal.pokeballSize
			height: internal.pokeballSize

			source: internal.pokeballUrl
		}

		Text {
			Layout.fillWidth: true
			Layout.fillHeight: true

			font {
				pixelSize: 12
				weight: Font.Medium
				family: "Poppins"
			}
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			text: root.dayOfWeek
		}
	}

	QtObject {
		id: internal

		readonly property int defaultWidth: 35
		readonly property int defaultHeight: 53

		readonly property int pokeballSize: 35

		readonly property string pokeballUrl: "qrc:/ui/assets_v2/pokeball.svg"
		readonly property string defaultDayOfWeek: "MON"
	}
}
