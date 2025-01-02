/******************************************************************************
**
** File      SaveDischargeSelector.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	signal save()
	signal discharge()

	property bool saveEnabled: false

	RowLayout {
		anchors.fill: parent
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

				source: root.saveEnabled ? internal.saveUrl : internal.grayedSaveUrl
				MouseArea {
					anchors.fill: parent
					onClicked: root.save()
				}
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
				MouseArea {
					anchors.fill: parent
					onClicked: root.discharge()
				}
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
	}

	QtObject {
		id: internal

		readonly property int spacing: 73
		readonly property int iconSize: 100

		readonly property string saveUrl: "qrc:/ui/assets/save.svg"
		readonly property string grayedSaveUrl: "qrc:/ui/assets/grayedsave.svg"
		readonly property string dischargeUrl: "qrc:/ui/assets/discharge.svg"
	}
}
