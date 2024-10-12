/******************************************************************************
**
** File      InfoTable.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	required property string hp
	required property string attack
	required property string defense
	required property string sAtk
	required property string sDef
	required property string speed
	required property string currentExp
	required property string baseExp
	property bool expTableEnabled: false

	ColumnLayout {
		id: statsTable

		visible: !root.expTableEnabled

		anchors.fill: parent

		spacing: 0

		StatBar {
			statName: "Hp"
			statValue: root.hp
		}
		StatBar {
			statName: "Attack"
			statValue: root.attack
		}
		StatBar {
			statName: "Defense"
			statValue: root.defense
		}
		StatBar {
			statName: "Sp.Atk"
			statValue: root.sAtk
		}
		StatBar {
			statName: "Sp.Def"
			statValue: root.sDef
		}
		StatBar {
			statName: "Speed"
			statValue: root.speed
		}
	}

	ColumnLayout {
		id: expTable

		visible: root.expTableEnabled

		anchors.fill: parent

		spacing: 0

		StatBar {
			statName: "Exp"
			statValue: root.currentExp
			statValueMax: root.baseExp
		}
	}
}
