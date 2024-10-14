/******************************************************************************
**
** File      CreateListFrame.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

ColumnLayout {
	id: root

	Rectangle {
		id: frameBorder

		Layout.fillWidth: true
		Layout.preferredHeight: 1

		color: UiConstant.pureBlack
	}

	Item {
		Layout.fillWidth: true
		Layout.fillHeight: true
	}

	RowLayout {
		Layout.fillWidth: true
		Layout.preferredHeight: internal.buttonHeight
		Layout.maximumHeight: internal.buttonHeight

		Rectangle {
			Layout.preferredWidth: internal.addButtonWidth
			Layout.fillHeight: true

			radius: internal.radius
			color: UiConstant.pureBlack_7

			RowLayout {
				anchors.fill: parent

				Image {
					width: internal.addIconSize
					height: internal.addIconSize

					Layout.leftMargin: 20

					source: internal.addIconUrl
				}

				Text {
					Layout.leftMargin: 20

					font {
						pixelSize: 18
						family: "Inter"
					}

					text: "New list"
				}

				Item {
					Layout.fillWidth: true
					Layout.fillHeight: true
				}
			}
		}
		Rectangle {
			Layout.preferredWidth: internal.addGroundButtonWidth
			Layout.fillHeight: true

			radius: internal.radius
			color: UiConstant.pureBlack_7

			Image {
				width: internal.addGroundIconSize
				height: internal.addGroundIconSize

				anchors.centerIn: parent
				source: internal.addGroundIconUrl
			}
		}
	}

	QtObject {
		id: internal

		readonly property int addButtonWidth: 295
		readonly property int addGroundButtonWidth: 46

		readonly property int buttonHeight: 45

		readonly property int radius: 8

		readonly property int addIconSize: 40
		readonly property int addGroundIconSize: 30

		readonly property string addIconUrl: "qrc:/ui/assets_v2/add.svg"
		readonly property string addGroundIconUrl: "qrc:/ui/assets_v2/squareAdd.svg"
	}
}
