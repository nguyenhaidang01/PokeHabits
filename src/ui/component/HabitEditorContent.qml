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
			}

			HabitNameDataField {
				id: habitNameDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 48
			}

			TargetDataField {
				id: targetDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 48
			}

			FrequencyDataField {
				id: frequencyDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 60
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
					root.controller.appendHabit(pokeId, habitName, targetUnit, targetValue, frequency);
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

		property QtObject uiService: root.controller ? root.controller.uiService : null
		readonly property int contentWidth: 834
		readonly property int contentHeight: 708
	}
}
