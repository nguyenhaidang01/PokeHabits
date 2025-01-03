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
	readonly property color silverGray: "#DBDBDB"

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

	// state
	readonly property string dashboardState: "dashboardState"
	readonly property string editState: "editState"
	readonly property string detailState: "detailState"

	// null value
	readonly property string nullstr: ""

	// map
	property var typeColorMap: {
		"normal": "#919AA2",
		"fire": "#FF9D55",
		"water": "#5090D6",
		"electric": "#F4D23C",
		"grass": "#63BC5A",
		"ice": "#73CEC0",
		"fighting": "#CE416B",
		"poison": "#B567CE",
		"ground": "#D97845",
		"flying": "#89AAE3",
		"psychic": "#FA7179",
		"bug": "#91C12F",
		"rock": "#C5B78C",
		"ghost": "#5269AD",
		"dragon": "#0B6DC3",
		"dark": "#5A5465",
		"steel": "#5A8EA2",
		"fairy": "#EC8FE6"
	}

	property var typeBackgroundColorMap: {
		"normal": "#F1F2F3",
		"fire": "#FCF3EB",
		"water": "#EBF1F8",
		"electric": "#FBF8E9",
		"grass": "#EDF6EC",
		"ice": "#F1FBF9",
		"fighting": "#F8E9EE",
		"poison": "#F5EDF8",
		"ground": "#F9EFEA",
		"flying": "#F1F4FA",
		"psychic": "#FCEEEF",
		"bug": "#F1F6E8",
		"rock": "#F7F5F1",
		"ghost": "#EBEDF4",
		"dragon": "#E4EEF6",
		"dark": "#ECEBED",
		"steel": "#ECF1F3",
		"fairy": "#FBF1FA"
	}

	property var typeColorImageUrlMap: {
		"normal": "qrc:/ui/assets/normal_color.svg",
		"fire": "qrc:/ui/assets/fire_color.svg",
		"water": "qrc:/ui/assets/water_color.svg",
		"electric": "qrc:/ui/assets/electric_color.svg",
		"grass": "qrc:/ui/assets/grass_color.svg",
		"ice": "qrc:/ui/assets/ice_color.svg",
		"fighting": "qrc:/ui/assets/fighting_color.svg",
		"poison": "qrc:/ui/assets/poison_color.svg",
		"ground": "qrc:/ui/assets/ground_color.svg",
		"flying": "qrc:/ui/assets/flying_color.svg",
		"psychic": "qrc:/ui/assets/psychic_color.svg",
		"bug": "qrc:/ui/assets/bug_color.svg",
		"rock": "qrc:/ui/assets/rock_color.svg",
		"ghost": "qrc:/ui/assets/ghost_color.svg",
		"dragon": "qrc:/ui/assets/dragon_color.svg",
		"dark": "qrc:/ui/assets/dark_color.svg",
		"steel": "qrc:/ui/assets/steel_color.svg",
		"fairy": "qrc:/ui/assets/fairy_color.svg"
	}

	property var typeImageUrlMap: {
		"normal": "qrc:/ui/assets/normal.svg",
		"fire": "qrc:/ui/assets/fire.svg",
		"water": "qrc:/ui/assets/water.svg",
		"electric": "qrc:/ui/assets/electric.svg",
		"grass": "qrc:/ui/assets/grass.svg",
		"ice": "qrc:/ui/assets/ice.svg",
		"fighting": "qrc:/ui/assets/fighting.svg",
		"poison": "qrc:/ui/assets/poison.svg",
		"ground": "qrc:/ui/assets/ground.svg",
		"flying": "qrc:/ui/assets/flying.svg",
		"psychic": "qrc:/ui/assets/psychic.svg",
		"bug": "qrc:/ui/assets/bug.svg",
		"rock": "qrc:/ui/assets/rock.svg",
		"ghost": "qrc:/ui/assets/ghost.svg",
		"dragon": "qrc:/ui/assets/dragon.svg",
		"dark": "qrc:/ui/assets/dark.svg",
		"steel": "qrc:/ui/assets/steel.svg",
		"fairy": "qrc:/ui/assets/fairy.svg"
	}
}
