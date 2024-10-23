/******************************************************************************
**
** File      HabitDetailView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Rectangle {
	id: root

	color: internal.backgroundColor

	ColumnLayout {
		anchors.fill: parent

		HeaderElement {
			id: header

			Layout.fillWidth: true
			Layout.preferredHeight: internal.headerHeight

			onExitView: function() {
				internal.mainLoader.changeToContentView();
			}
		}

		Item {
			id: detail

			Layout.fillWidth: true
			Layout.fillHeight: true

			Item {
				implicitWidth: 844
				implicitHeight: 678

				anchors.centerIn: parent

				ColumnLayout {
					anchors.fill: parent

					PokemonInfo {
						id: pokemonInfo

						Layout.preferredWidth: 256
						Layout.preferredHeight: 126

						Layout.alignment: Qt.AlignTop
					}

					HabitStatsBoard {
						id: habitStatsBoard

						Layout.fillWidth: true
						Layout.preferredHeight: 194

						strentch: 100
						currentExp: 100
						currentLvl: 15
						unit: 1
						startDate: "10/10/2024"
						frequency: "everyday"
					}

					EvolChainBoard {
						id: evolChainBoard

						Layout.fillWidth: true
						Layout.preferredHeight: 260

						Layout.alignment: Qt.AlignBottom
					}
				}
			}
		}
	}

	HabitNameWithPoke {
		id: habitNameWithPoke

		implicitWidth: parent.width
		anchors {
			horizontalCenter: parent.horizontalCenter
			top: parent.top
			topMargin: internal.headerHeight/2
		}

		habitName: internal.defaultHabitName
		pokemonUrl: internal.defaultPokemonUrl

		onOpenEditorView: function() {
			internal.mainLoader.changeToHabitEditorView();
		}
	}

	QtObject {
		id: internal

		readonly property QtObject mainLoader: root.parent

		readonly property int circleHeaderSize: 2000
		readonly property int headerHeight: 222

		readonly property int pokedexPopupWidth: 840
		readonly property int pokedexPopupHeight: 922

		readonly property string defaultHabitName: "Go Gym"
		readonly property string defaultPokemonUrl: "qrc:/ui/assets_v2/bulbasaur.svg"

		readonly property string editUrl: "qrc:/ui/assets_v2/pen.svg"
		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
