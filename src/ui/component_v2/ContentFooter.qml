/******************************************************************************
**
** File      ContentFooter.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	Rectangle {
		implicitWidth: parent.width
		implicitHeight: 62

		anchors.bottom: parent.bottom

		radius: internal.radius
		border.width: internal.borderWidth

		RowLayout {
			anchors.fill: parent

			Image {
				id: pokeball

				width: internal.pokeballSize
				height: internal.pokeballSize

				Layout.leftMargin: 43
				source: "qrc:/ui/assets_v2/pokeball.svg"
			}

			Text {
				Layout.leftMargin: 40

				font {
					pixelSize: 21
					weight: Font.Medium
					family: "Poppins"
				}

				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter

				text: "Add a habit"
			}

			Item {
				Layout.fillWidth: true
				Layout.fillHeight: true
			}
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 8
		readonly property real borderWidth: 0.5
		readonly property int pokeballSize: 40
	}
}
