/******************************************************************************
**
** File      Main.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls

ApplicationWindow  {
	id: root

	visible: true

	width: internal.windowWidth
	height: internal.windowHeight

	title: qsTr("Pokemon Habit")

	MainView {
		id: mainView
		anchors.fill: parent
	}

	QtObject {
		id: internal

		readonly property int windowWidth: 1280
		readonly property int windowHeight: 960
	}
}
