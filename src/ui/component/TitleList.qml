/******************************************************************************
**
** File      TitleList.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

ListView {
	id: root

	spacing: internal.spacing
	interactive: false

	model: 1
	delegate: TitleFrame {}

	QtObject {
		id: internal

		readonly property int spacing: 14
	}
}
