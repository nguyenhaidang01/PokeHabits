/******************************************************************************
**
** File      HeaderElement.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import "../component_v2"

Item {
	id: root

	signal exitView()

	clip: true

	Item {
		implicitWidth: internal.circleHeaderSize
		implicitHeight: internal.circleHeaderSize

		anchors {
			horizontalCenter: parent.horizontalCenter
			bottom: parent.bottom
		}

		LinearGradient {
			anchors.fill: parent

			start: Qt.point(0, 0)
			end: Qt.point(0, internal.circleHeaderSize)
			gradient: Gradient {
				GradientStop { position: 0.0; color: internal.headerColor }
				GradientStop { position: 1.0; color: internal.headerColor_50 }
			}
			source: Rectangle {
				implicitWidth: internal.circleHeaderSize
				implicitHeight: internal.circleHeaderSize
				radius: internal.circleHeaderSize/2
			}
		}
	}

	Item {
		implicitWidth: internal.defaultHeaderWidth
		implicitHeight: parent.height

		anchors.centerIn: parent

		Image {
			id: element

			width: internal.elementSize
			height: internal.elementSize

			anchors.centerIn: parent
			source: internal.elementUrl
		}

		Image {
			id: back

			width: internal.backSize
			height: internal.backSize

			anchors {
				left: parent.left
				top: parent.top
				topMargin: 20
			}

			source: internal.backUrl

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					exitView();
				}
			}
		}

		Image {
			id: favorite

			width: internal.favoriteSize
			height: internal.favoriteSize

			anchors {
				right: parent.right
				top: parent.top
				rightMargin: 24
				topMargin: 25
			}

			source: internal.favoriteUrl
		}
	}

	QtObject {
		id: internal

		readonly property int circleHeaderSize: 2000
		readonly property int defaultHeaderWidth: 930

		readonly property int elementSize: 200
		readonly property int backSize: 70
		readonly property int favoriteSize: 50

		readonly property string elementUrl: "qrc:/ui/assets_v2/grass.svg"
		readonly property string backUrl: "qrc:/ui/assets_v2/leftarrow.svg"
		readonly property string favoriteUrl: "qrc:/ui/assets_v2/lightfavorite.svg"

		readonly property color headerColor: UiConstant.grassColor
		readonly property color headerColor_50: Qt.rgba(headerColor.r, headerColor.g, headerColor.b, 0.5)
	}
}
