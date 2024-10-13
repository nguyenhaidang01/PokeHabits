/******************************************************************************
**
** File      ContentView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Rectangle {
	id: root

	color: internal.backgroundColor

	ColumnLayout {
		id: contentLayout

		anchors.fill: parent
		anchors.margins: internal.contentMargin

		spacing: 0

		ContentHeader {
			id: contentHeader

			Layout.fillWidth: true
			Layout.preferredHeight: 60
		}

		RowLayout {
			id: listContentFrame

			Layout.fillWidth: true
			Layout.fillHeight: true

			Rectangle {
				Layout.fillWidth: true
				Layout.fillHeight: true

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
