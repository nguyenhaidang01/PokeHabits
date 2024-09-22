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

	Rectangle {
		id: habitTitle

		Layout.preferredWidth: parent.width
		Layout.preferredHeight: 32

		color: UiStyle.obsidian_10
		Label {
			id: nameLabel

			anchors {
				verticalCenter: parent.verticalCenter
				left: parent.left
				leftMargin: 26
			}

			font {
				bold: true
				italic: true
				pixelSize: 18
				family: "Roboto"
				strikeout: done
			}
			text: habitName
			color: done? UiStyle.mintGreen : UiStyle.etherealWhite
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

		Item {
			id: pkmInfo

			Layout.fillWidth: true
			Layout.preferredHeight: 145

			ColumnLayout {
				anchors.fill: parent

				spacing: 0

				StatBar {
					statName: "Hp"
					statValue: pkmHpStat
				}
				StatBar {
					statName: "Attack"
					statValue: pkmAttack
				}
				StatBar {
					statName: "Defense"
					statValue: pkmDefense
				}
				StatBar {
					statName: "Sp.Atk"
					statValue: pkmSAttack
				}
				StatBar {
					statName: "Sp.Def"
					statValue: pkmSDefense
				}
				StatBar {
					statName: "Speed"
					statValue: pkmSpeed
				}
			}
		}
	}

	QtObject {
		id: internal

		property bool feedboxOpened: false
		readonly property int gridCellWidth: 476
		readonly property int gridCellHeight: 187
		readonly property int radius: 6
		readonly property url examplePokemon: "qrc:/ui/assets/leafeon.png"
		readonly property url doneFruit: "qrc:/ui/assets/goldenrazzberry.png"
		readonly property url incompleteFruit: "qrc:/ui/assets/silverpinapberry.png"
	}
}
