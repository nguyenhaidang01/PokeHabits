/******************************************************************************
**
** File      HabitInfo.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	required property string habitName
	required property string pokemonName
	required property int exp
	required property int baseExp
	required property string pokeFirstType
	required property string pokeSecondType

	implicitWidth: 275
	implicitHeight: 115

	ColumnLayout {
		anchors.fill: parent

		Text {
			id: pokemonName

			font {
				pixelSize: 12
				weight: Font.DemiBold
				family: "Poppins"
			}

			text: root.pokemonName
		}

		Text {
			id: habitName

			font {
				pixelSize: 21
				weight: Font.DemiBold
				family: "Poppins"
			}

			text: root.habitName
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 16

			Text {
				font {
					pixelSize: 10
					weight: Font.Bold
					family: "Poppins"
				}

				text: "EXP"
				color: UiConstant.typeColorMap[pokeFirstType]
			}

			Text {
				id: exp

				font {
					pixelSize: 10
					weight: Font.Bold
					family: "Poppins"
				}

				text: ("000" + root.exp).slice(-3) + "/" + ("000" + root.baseExp).slice(-3)
				color: "#1D1D1D"
			}

			Rectangle {
				Layout.preferredWidth: 200
				Layout.preferredHeight: 7

				Layout.alignment: Qt.AlignRight

				radius: 4
				border.width: 0.5

				color: UiConstant.pureWhite

				Rectangle {
					width: parent.width * (root.exp/root.baseExp)
					height: parent.height

					radius: 4
					border.width: 0.5

					color: UiConstant.typeColorMap[pokeFirstType]
				}
			}
		}

		ListModel {
			id: elementModel

			Component.onCompleted: function() {
				elementModel.append({ name: root.pokeFirstType });
				if (root.pokeSecondType !== UiConstant.nullstr) {
					elementModel.append({ name: root.pokeSecondType });
				}
			}
		}

		ListView {
			id: elementListView

			Layout.preferredWidth: 210
			Layout.preferredHeight: 26

			orientation: ListView.Horizontal
			spacing: 20

			model: elementModel
			delegate: ElementFrame { elementName: name }
		}
	}
}
