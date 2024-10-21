/******************************************************************************
**
** File      HabitStat.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property string stateName
	property string stateValue

	implicitWidth: internal.defaultWidth
	implicitHeight: internal.defaultHeight

	ColumnLayout {
		anchors.fill: parent

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 21

			spacing: 6

			Item {
				Layout.preferredWidth: internal.pokeballSize
				Layout.preferredHeight: internal.pokeballSize

				Layout.alignment: Qt.AlignVCenter

				Image {
					anchors.fill: parent
					source: internal.pokeballUrl
				}
			}

			Text {
				Layout.fillWidth: true
				Layout.preferredHeight: 21

				Layout.alignment: Qt.AlignVCenter

				font {
					pixelSize: 14
					weight: Font.Medium
					family: "Poppins"
				}

				verticalAlignment: Text.AlignVCenter
				text:root.stateName
			}
		}

		Rectangle {
			Layout.fillWidth: true
			Layout.preferredHeight: 43

			Layout.alignment: Qt.AlignBottom

			radius: internal.radius
			border.width: internal.borderWidth

			Text {
				anchors.fill: parent

				font {
					pixelSize: 14
					weight: Font.Medium
					family: "Poppins"
				}

				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter

				text: root.stateValue
			}
		}
	}

	QtObject {
		id: internal

		readonly property int defaultWidth: 154
		readonly property int defaultHeight: 68

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property int pokeballSize: 16
		readonly property string pokeballUrl: "qrc:/ui/assets_v2/pokeball.svg"
	}
}
