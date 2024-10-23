/******************************************************************************
**
** File      ViewV2.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

ApplicationWindow  {
	id: root

	visible: true

	width: internal.windowWidth
	height: internal.windowHeight

	title: qsTr("Pokemon Habit")

	RowLayout {
		anchors.fill: parent
		spacing: 0

		SidebarView {
			id: sidebarView

			Layout.preferredWidth: internal.sidebarWidth
			Layout.maximumWidth: internal.sidebarWidth
			Layout.fillHeight: true
		}

		MainViewLoader {
			id: mainViewLoader

			Layout.fillWidth: true
			Layout.fillHeight: true

			contentViewSource: contentView
			habitEditorViewSource: habitEditorView
			habitDetailViewSource: habitDetailView
		}

		Component {
			id: contentView

			ContentView {}
		}

		Component {
			id: habitEditorView

			HabitEditorView {}
		}

		Component {
			id: habitDetailView

			HabitDetailView {}
		}
	}

	QtObject {
		id: internal

		readonly property int windowWidth: 1280
		readonly property int windowHeight: 960

		readonly property int sidebarWidth: 350
	}
}
