/******************************************************************************
**
** File      HabitStatsBoard.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	property var habitData

	ColumnLayout {
		anchors.fill: parent

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 68

			spacing: 76

			Layout.alignment: Qt.AlignTop

			HabitStat {
				stateName: "START DATE"
				stateValue: root.habitData.startDate
			}

			HabitStat {
				stateName: "STRENTCH"
				stateValue: root.habitData.stretch
			}

			HabitStat {
				stateName: "CURRENT EXP"
				stateValue: root.habitData.pokeExp
			}

			HabitStat {
				stateName: "CURRENT LVL"
				stateValue: root.habitData.pokeLvl
			}
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 68

			Layout.alignment: Qt.AlignBottom

			spacing: internal.spacing

			HabitStat {
				stateName: "UNIT"
				stateValue: root.habitData.targetValue
			}

			HabitStat {
				stateName: "FREQUENCY"
				stateValue: root.habitData.frequency
			}

			Item {
				Layout.fillWidth: true
				Layout.preferredHeight: 68
			}
		}
	}

	QtObject {
		id: internal

		readonly property int spacing: 76
	}
}
