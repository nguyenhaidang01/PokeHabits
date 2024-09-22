/******************************************************************************
**
** File      UiStyle.qml
** Author    Dang Nguyen
**
******************************************************************************/

pragma Singleton
import QtQuick

QtObject {
	id: root

	// string
	readonly property string nullString: ""

	// color
	readonly property color transparent: "transparent"
	readonly property color obsidian: "#000000"
	readonly property color etherealWhite: "#FFFFFF"
	readonly property color ghostWhite: "#FCFCFC"
	readonly property color cherryRed: "#FF4949"
	readonly property color goldenYellow: "#ebc221"
	readonly property color mysticOcean: "#465d5b"
	readonly property color mistyAqua: "#c1c9c9"
	readonly property color mintGreen: "#48D0B0"

	// rgba color
	readonly property color obsidian_10: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.1)
	readonly property color obsidian_40: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.4)
	readonly property color obsidian_50: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.5)
	readonly property color obsidian_70: Qt.rgba(obsidian.r, obsidian.g, obsidian.b, 0.7)

	readonly property color ghostWhite_0: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0)

	readonly property color etherealWhite_11: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0.11)
	readonly property color etherealWhite_12: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0.12)
	readonly property color etherealWhite_20: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0.2)
	readonly property color etherealWhite_87: Qt.rgba(etherealWhite.r, etherealWhite.g, etherealWhite.b, 0.87)
}
