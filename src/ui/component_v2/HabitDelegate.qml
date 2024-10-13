/******************************************************************************
**
** File      HabitDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Rectangle {
	id: root

	radius: internal.radius
	color: internal.defaultElementColor

	RowLayout {
		anchors.fill: parent

		Rectangle {
			Layout.preferredWidth: internal.checkboxSize
			Layout.preferredHeight: internal.checkboxSize

			Layout.leftMargin: 20

			radius: internal.checkboxSize/2
			color: UiConstant.pureBlack_7
		}

		PokemonFrame {
			Layout.leftMargin: 20
		}

		HabitInfo {
			id: habitInfo

			Layout.preferredWidth: 275
			Layout.preferredHeight: 115

			Layout.leftMargin: 25
		}

		Item {
			Layout.fillWidth: true
			Layout.fillHeight: true
		}

		Image {
			id: favorite

			width: internal.favoriteSize
			height: internal.favoriteSize

			Layout.bottomMargin: 80
			Layout.rightMargin: 15

			source: "qrc:/ui/assets_v2/favorite.svg"
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property int checkboxSize: 50
		readonly property int favoriteSize: 50
		readonly property color defaultElementColor: UiConstant.lightGrassColor
	}
}
