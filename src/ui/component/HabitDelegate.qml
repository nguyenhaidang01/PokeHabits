/******************************************************************************
**
** File      HabitDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Rectangle {
	id: root

	signal openDetailHabit()
	signal requestChangeDoneStatus(bool status)

	property string habitName
	property bool doneStatus
	property int exp
	property string pokeName
	property string pokeImage
	property int pokeBaseExp

	property string elementUrl: internal.defaultElementUrl

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

			Image {
				visible: root.doneStatus
				anchors.fill: parent
				source: "qrc:/ui/assets/done.svg"
			}

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					root.requestChangeDoneStatus(!root.doneStatus);
				}
			}
		}

		PokemonFrame {
			Layout.leftMargin: 20

			elementUrl: root.elementUrl
			pokemonImage: root.pokeImage

			MouseArea {
				anchors.fill: parent
				onClicked: root.openDetailHabit()
			}
		}

		HabitInfo {
			id: habitInfo

			Layout.preferredWidth: 275
			Layout.preferredHeight: 115

			Layout.leftMargin: 25

			habitName: root.habitName
			pokemonName: root.pokeName
			exp: root.exp
			baseExp: root.pokeBaseExp

			MouseArea {
				anchors.fill: parent
				onClicked: openDetailHabit()
			}
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

			source: "qrc:/ui/assets/favorite.svg"
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property int checkboxSize: 50
		readonly property int favoriteSize: 50
		readonly property color defaultElementColor: UiConstant.lightGrassColor
		readonly property string defaultElementUrl: "qrc:/ui/assets/grass.svg"
	}
}
