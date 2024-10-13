/******************************************************************************
**
** File      ContentView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Rectangle {
	id: root

	color: internal.backgroundColor

	ColumnLayout {
		id: contentLayout

		anchors.fill: parent
		spacing: 0

		RowLayout {
			id: listContentFrame

			Layout.fillWidth: true
			Layout.fillHeight: true

			Rectangle {
				Layout.fillWidth: true
				Layout.fillHeight: true

				Layout.margins: internal.contentMargin
				color: "blue"
			}
		}
	}

	QtObject {
		id: internal

		readonly property int contentMargin: 60
		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
