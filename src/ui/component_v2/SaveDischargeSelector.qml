/******************************************************************************
**
** File      SaveDischargeSelector.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

RowLayout {
	id: root

	spacing: internal.spacing

	Item {
		Layout.preferredWidth: internal.iconSize
		Layout.fillHeight: true
	}

	ColumnLayout {
		Layout.preferredWidth: internal.iconSize
		Layout.fillHeight: true

		spacing: 0

		Image {
			width: internal.iconSize
			height: internal.iconSize

			source: internal.saveUrl
		}

		Text {
			Layout.preferredWidth: internal.iconSize
			Layout.preferredHeight: 32

			font {
				pixelSize: 21
				weight: Font.Medium
				family: "Poppins"
			}
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

			text: "Save"
		}
	}

	ColumnLayout {
		Layout.preferredWidth: internal.iconSize
		Layout.fillHeight: true

		spacing: 0

		Image {
			width: internal.iconSize
			height: internal.iconSize

			source: internal.dischargeUrl
		}

		Text {
			Layout.preferredWidth: internal.iconSize
			Layout.preferredHeight: 32

			font {
				pixelSize: 21
				weight: Font.Medium
				family: "Poppins"
			}
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

			text: "Discharge"
		}
	}

	QtObject {
		id: internal

		readonly property int spacing: 73
		readonly property int iconSize: 100

		readonly property string saveUrl: "qrc:/ui/assets_v2/save.svg"
		readonly property string dischargeUrl: "qrc:/ui/assets_v2/discharge.svg"
	}
}
