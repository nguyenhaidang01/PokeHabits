/******************************************************************************
**
** File      ElementIcon.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import "../component"

Rectangle {
	id: root

	property string elementName: internal.defaultElementName
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

		source: root.elementName !== UiConstant.nullstr ?
					UiConstant.typeColorImageUrlMap[root.elementName] :
					UiConstant.typeColorImageUrlMap[internal.defaultElementName]
	}

	QtObject {
		id: internal

		readonly property int defaultBackgroundSize: 20
		readonly property int defaultElementSize: 13
		readonly property string defaultElementName: "grass"
	}
}
