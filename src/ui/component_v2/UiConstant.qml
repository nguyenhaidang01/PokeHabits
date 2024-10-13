/******************************************************************************
**
** File      UiConstant.qml
** Author    Dang Nguyen
**
******************************************************************************/

pragma Singleton
import QtQuick

QtObject {
	id: root

	// color
	readonly property color transparent: "transparent"
	readonly property color pureBlack: "#000000"
	readonly property color pureWhite: "#FFFFFF"

	readonly property color lightGray: "#F2F2F2"

	// rgba color
	readonly property color pureBlack_7: Qt.rgba(pureBlack.r, pureBlack.g, pureBlack.b, 0.07)
}
