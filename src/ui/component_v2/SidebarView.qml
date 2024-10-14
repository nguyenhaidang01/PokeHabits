/******************************************************************************
**
** File      SidebarView.qml
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
		id: sidebarLayout

		anchors.fill: parent
		spacing: 0

		ProfileToolFrame {
			id: profileToolFrame

			Layout.fillWidth: true
			Layout.preferredHeight: internal.profileToolFrameHeight
		}

		TitleList {
			id: titleList

			Layout.fillWidth: true
			Layout.preferredHeight: internal.listTitleHeight
			Layout.maximumHeight: internal.listTitleHeight
		}

		Rectangle {
			id: createListFrame

			Layout.fillWidth: true
			Layout.fillHeight: true
			color: "pink"
		}
	}

	QtObject {
		id: internal

		readonly property int sidebarWidth: 350

		readonly property int profileToolFrameHeight: 140
		readonly property int listTitleHeight: 410

		readonly property color backgroundColor: UiConstant.lightGray
	}
}
