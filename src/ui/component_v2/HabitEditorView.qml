/******************************************************************************
**
** File      HabitEditorView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import "../component_v2"

Rectangle {
	id: root

	color: internal.backgroundColor

	ColumnLayout {
		anchors.fill: parent

		HeaderElement {
			id: header

			Layout.fillWidth: true
			Layout.preferredHeight: internal.headerHeight
		}

		HabitEditorContent {
			id: habitEditorContent

			Layout.fillWidth: true
			Layout.fillHeight: true
		}
	}

	QtObject {
		id: internal

		readonly property int circleHeaderSize: 2000
		readonly property int headerHeight: 222

		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
