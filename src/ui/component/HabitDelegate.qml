/******************************************************************************
**
** File      HabitDelegate.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

ColumnLayout {
	id: root

	implicitWidth: 414
	implicitHeight: 181

	spacing: 4

	HabitTitle {
		id: habitTitle

		Layout.preferredWidth: parent.width
		Layout.preferredHeight: 32

		title: habitName
		isDone: done

		onSwitchClicked: function() {
			internal.expTableEnabled = !internal.expTableEnabled;
		}
	}

	RowLayout {
		id: habitItem

		Layout.fillWidth: true
		Layout.preferredHeight: 145

		GradientFrame {
			id: feedbox

			visible: internal.feedboxOpened

			Layout.preferredWidth: 40
			Layout.preferredHeight: 40

			onClicked: function() {
				done = !done;
				exp += done? 1 : -1;
				internal.feedboxOpened = !internal.feedboxOpened;
			}

			Image {
				anchors.fill: parent
				source: done? internal.incompleteFruit : internal.doneFruit
			}
		}

		Item {
			visible: !internal.feedboxOpened

			Layout.preferredWidth: 25
			Layout.fillHeight: true
		}

		PokemonFrame {
			id: habitRepresent

			Layout.preferredWidth: 120
			Layout.preferredHeight: 142

			pokemonImg: pkmImageSvg
			pokemonName: pkmName
			twinkle: done

			onClicked: function() {
				internal.feedboxOpened = !internal.feedboxOpened;
			}
		}

		InfoTable {
			id: pkmInfo

			Layout.fillWidth: true
			Layout.preferredHeight: 145

			hp: pkmHp
			attack: pkmAttack
			defense: pkmDefense
			sAtk: pkmSAttack
			sDef: pkmSDefense
			speed: pkmSpeed
			baseExp: pkmBaseExp
			currentExp: exp

			expTableEnabled: internal.expTableEnabled
		}
	}

	QtObject {
		id: internal

		property bool expTableEnabled: false
		property bool feedboxOpened: false
		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
		readonly property int radius: 6
		readonly property url examplePokemon: "qrc:/ui/assets/leafeon.png"
		readonly property url doneFruit: "qrc:/ui/assets/goldenrazzberry.png"
		readonly property url incompleteFruit: "qrc:/ui/assets/silverpinapberry.png"
	}
}
