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
	property string pokeFirstType
	property string pokeSecondType

	radius: internal.radius
	color: UiConstant.typeBackgroundColorMap[pokeFirstType]

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

			pokeImage: root.pokeImage
			pokeType: root.pokeFirstType

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
			pokeFirstType: root.pokeFirstType
			pokeSecondType: root.pokeSecondType

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
	}
}
