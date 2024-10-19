/******************************************************************************
**
** File      HabitEditorContent.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property Popup pokedexPopup: null

	Item {
		implicitWidth: internal.contentWidth
		implicitHeight: internal.contentHeight

		anchors.centerIn: parent

		ColumnLayout {
			anchors.fill: parent
			spacing: 55

			TargetPokeDataField {
				id: targetPokeDataField

				Layout.maximumWidth: 517
				Layout.preferredWidth: 517
				Layout.preferredHeight: 200

				pokedexPopup: root.pokedexPopup
			}

			HabitNameDataField {
				id: habitNameDataField

				Layout.fillWidth: true
				Layout.preferredHeight: 48
			}

			TimeDataField {
				id: timeDataField

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
			}
		}
	}

	QtObject {
		id: internal

		readonly property int contentWidth: 834
		readonly property int contentHeight: 708
	}
}
