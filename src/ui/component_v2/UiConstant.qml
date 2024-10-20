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

	readonly property color normalColor: "#919AA2"
	readonly property color fireColor: "#FF9D55"
	readonly property color waterColor: "#5090D6"
	readonly property color electricColor: "#F4D23C"
	readonly property color grassColor: "#63BC5A"
	readonly property color iceColor: "#73CEC0"
	readonly property color fightingColor: "#CE416B"
	readonly property color poisonColor: "#B567CE"
	readonly property color groundColor: "#D97845"
	readonly property color flyingColor: "#89AAE3"
	readonly property color psychicColor: "#FA7179"
	readonly property color bugColor: "#91C12F"
	readonly property color rockColor: "#C5B78C"
	readonly property color ghostColor: "#5269AD"
	readonly property color dragonColor: "#0B6DC3"
	readonly property color darkColor: "#5A5465"
	readonly property color steelColor: "#5A8EA2"
	readonly property color fairyColor: "#EC8FE6"

	readonly property color lightNormalColor: "#F1F2F3"
	readonly property color lightFireColor: "#FCF3EB"
	readonly property color lightWaterColor: "#EBF1F8"
	readonly property color lightElectricColor: "#FBF8E9"
	readonly property color lightGrassColor: "#EDF6EC"
	readonly property color lightIceColor: "#F1FBF9"
	readonly property color lightFightingColor: "#F8E9EE"
	readonly property color lightPoisonColor: "#F5EDF8"
	readonly property color lightGroundColor: "#F9EFEA"
	readonly property color lightFlyingColor: "#F1F4FA"
	readonly property color lightPsychicColor: "#FCEEEF"
	readonly property color lightBugColor: "#F1F6E8"
	readonly property color lightRockColor: "#F7F5F1"
	readonly property color lightGhostColor: "#EBEDF4"
	readonly property color lightDragonColor: "#E4EEF6"
	readonly property color lightDarkColor: "#ECEBED"
	readonly property color lightSteelColor: "#ECF1F3"
	readonly property color lightFairyColor: "#FBF1FA"

	// rgba color
	readonly property color pureBlack_7: Qt.rgba(pureBlack.r, pureBlack.g, pureBlack.b, 0.07)

	// string
	readonly property string displayHabitsState: "displayHabits"
	readonly property string addHabitState: "addHabit"
}
