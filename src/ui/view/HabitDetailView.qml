/******************************************************************************
**
** File      HabitDetailView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Rectangle {
	id: root

	property QtObject controller: null

	color: internal.backgroundColor

	ColumnLayout {
		anchors.fill: parent

		HeaderElement {
			id: header

			Layout.fillWidth: true
			Layout.preferredHeight: internal.headerHeight

			onExitView: function() {
				internal.uiService.changeToHabitDashboardView();
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

						pokemonId: internal.selectedHabit.pokeId
						pokemonName: internal.pokemonHelper.pokemonName(pokemonId)
					}

					HabitStatsBoard {
						id: habitStatsBoard

						Layout.fillWidth: true
						Layout.preferredHeight: 194

						habitData: internal.selectedHabit
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

		habitName: internal.selectedHabit.name
		pokemonImage: internal.selectedPokemonImage

		onOpenEditorView: function() {
			internal.uiService.changeToHabitEditorView(internal.habitModel.selectedHabitIndex);
		}
	}

	QtObject {
		id: internal

		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null
		property QtObject uiService: root.controller ? root.controller.uiService : null
		property QtObject habitModel: root.controller ? root.controller.habitModel : null

		property var selectedHabit: habitModel.get(habitModel.selectedHabitIndex)
		property int selectedPokemonId: selectedHabit.pokeId
		property string selectedPokemonImage: pokemonHelper.pokemonImage(selectedPokemonId)

		readonly property int circleHeaderSize: 2000
		readonly property int headerHeight: 222

		readonly property int pokedexPopupWidth: 840
		readonly property int pokedexPopupHeight: 922

		readonly property string editUrl: "qrc:/ui/assets/pen.svg"
		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
