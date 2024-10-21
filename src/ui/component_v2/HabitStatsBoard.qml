/******************************************************************************
**
** File      HabitStatsBoard.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property string startDate
	property int strentch
	property int currentExp
	property int currentLvl
	property int unit
	property string frequency

	ColumnLayout {
		anchors.fill: parent

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 68

			spacing: 76

			Layout.alignment: Qt.AlignTop

			HabitStat {
				stateName: "START DATE"
				stateValue: root.startDate
			}

			HabitStat {
				stateName: "STRENTCH"
				stateValue: root.strentch
			}

			HabitStat {
				stateName: "CURRENT EXP"
				stateValue: root.currentExp
			}

			HabitStat {
				stateName: "CURRENT LVL"
				stateValue: root.currentLvl
			}
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 68

			Layout.alignment: Qt.AlignBottom

			spacing: internal.spacing

			HabitStat {
				stateName: "UNIT"
				stateValue: root.unit
			}

			HabitStat {
				stateName: "FREQUENCY"
				stateValue: root.frequency
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
