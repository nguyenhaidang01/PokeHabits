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

		Item {
			Layout.fillWidth: true
			Layout.preferredHeight: 20
		}

		ListView {
			Layout.fillWidth: true
			Layout.fillHeight: true

			clip: true

			spacing:24
			model: 10

			delegate: HabitDelegate {
				implicitWidth: internal.habitDelegateWidth
				implicitHeight: 145
			}
		}

		ContentFooter {
			id: contentFooter

			Layout.fillWidth: true
			Layout.preferredHeight: 112

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					internal.mainLoader.state = UiConstant.addHabitState;
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property QtObject mainLoader: root.parent

		readonly property int contentMargin: 60
		readonly property int habitDelegateWidth: root.width - 2 * contentMargin
		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
