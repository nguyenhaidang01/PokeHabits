/******************************************************************************
**
** File      ElementIcon.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component_v2"

Rectangle {
	id: root

	property int elementSize: internal.defaultElementSize
	property int backgroundSize: internal.defaultBackgroundSize

	implicitWidth: backgroundSize
	implicitHeight: backgroundSize

	radius: backgroundSize/2
	color: UiConstant.pureWhite

	Image {
		id: element

		width: root.elementSize
		height: root.elementSize

		anchors.centerIn: parent

		source: internal.elementUrl
	}

	QtObject {
		id: internal

		readonly property int defaultBackgroundSize: 20
		readonly property int defaultElementSize: 13
		readonly property string elementUrl: "qrc:/ui/assets_v2/grassColor.svg"
	}
}
