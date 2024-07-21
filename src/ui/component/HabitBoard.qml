/******************************************************************************
**
** File      HabitBoard.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls

Item {
	id: root

	implicitWidth: 952
	implicitHeight: 374

	property QtObject model: null

	GridView {
		id: habitList

		anchors.fill: parent

		model: root.model
		delegate: gridDelegate

		cellWidth: internal.gridCellWidth
		cellHeight: internal.gridCellHeight

		clip: true
	}

	Component {
		id: gridDelegate

		HabitDelegate {
			id: habitDelegate
		}
	}

	QtObject {
		id: internal

		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
	}
}
