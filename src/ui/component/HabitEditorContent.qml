/******************************************************************************
**
** File      HabitEditorContent.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	property Popup pokedexPopup: null
	property QtObject controller: null
	property int editHabitIndex

	Item {
		implicitWidth: internal.contentWidth
		implicitHeight: internal.contentHeight

		anchors.centerIn: parent

		ColumnLayout {
			anchors.fill: parent
			spacing: 55

			PokemonDataField {
				id: targetPokeDataField

				Layout.maximumWidth: 517
				Layout.preferredWidth: 517
				Layout.preferredHeight: 200

				controller: root.controller
				pokedexPopup: root.pokedexPopup
				pokeId: root.editHabitIndex !== internal.appendIndex ?
							internal.editHabit.pokeId : internal.defaultPokeId
			}

			HabitNameDataField {
				id: habitNameDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 48

				habitName: root.editHabitIndex !== internal.appendIndex ?
							   internal.editHabit.name : null
			}

			TargetDataField {
				id: targetDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 48

				unit: root.editHabitIndex !== internal.appendIndex ?
						  internal.editHabit.targetUnit : internal.defaulTargetUnit
				value: root.editHabitIndex !== internal.appendIndex ?
						   internal.editHabit.targetValue : null
			}

			FrequencyDataField {
				id: frequencyDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 60

				frequency: root.editHabitIndex !== internal.appendIndex ?
							   internal.editHabit.frequency : "everyday"
			}

			SaveDischargeSelector {
				id: saveDischargeSelector

				Layout.preferredWidth: 446
				Layout.preferredHeight: 132

				Layout.alignment: Qt.AlignHCenter

				onSave: function() {
					var pokeId = targetPokeDataField.pokeId;
					var habitName = habitNameDataField.habitName;
					var targetUnit = targetDataField.unit;
					var targetValue = targetDataField.value;
					var frequency = frequencyDataField.frequency;

					if (root.editHabitIndex == internal.appendIndex) {
						root.controller.appendHabit(pokeId, habitName, targetUnit, targetValue, frequency);
					} else {
						root.controller.replaceHabit(root.editHabitIndex, pokeId, habitName,
													 targetUnit, targetValue, frequency);
					}

					internal.uiService.changeToPreviousView();
				}
				onDischarge: internal.uiService.changeToPreviousView();
			}
		}
	}

	Connections {
		target: root.pokedexPopup

		function onSelectedIdChanged(id) {
			targetPokeDataField.pokeId = id;
		}
	}

	QtObject {
		id: internal

		readonly property int appendIndex: -1
		readonly property int defaultPokeId: 1
		readonly property string defaulTargetUnit: "Time"

		property QtObject uiService: root.controller ? root.controller.uiService : null
		property QtObject habitModel: root.controller ? root.controller.habitModel : null

		property var editHabit: root.editHabitIndex !== appendIndex ?
									    habitModel.get(root.editHabitIndex) : null

		readonly property int contentWidth: 834
		readonly property int contentHeight: 708
	}
}
