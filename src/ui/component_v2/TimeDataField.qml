/******************************************************************************
**
** File      TimeDataField.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

RowLayout {
	id: root

	property alias unit: unit.text

	Layout.fillWidth: true
	Layout.preferredHeight: 48

	spacing: 0

	Item {
		Layout.preferredWidth: 317
		Layout.fillHeight: true

		TextWithPokeball {
			anchors.verticalCenter: parent.verticalCenter
			text: "TIME"
		}
	}

	RowLayout {
		Layout.fillWidth: true
		Layout.fillHeight: true

		Rectangle {
			Layout.preferredWidth: 400
			Layout.fillHeight: true

			radius: internal.radius
			border.width: internal.borderWidth

			Text {
				anchors.fill: parent

				font {
					pixelSize: 21
					weight: Font.Medium
					family: "Poppins"
				}
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				text: "1"
			}
		}

		Item {
			Layout.fillWidth: true
			Layout.fillHeight: true
		}

		Rectangle {
			Layout.preferredWidth: 100
			Layout.fillHeight: true

			radius: internal.radius
			border.width: internal.borderWidth

			Text {
				id: unit

				anchors.fill: parent

				font {
					pixelSize: 21
					weight: Font.Medium
					family: "Poppins"
				}
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter

				text: internal.getUnit(internal.unitIndex)
			}

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					internal.gainUnitIndex();
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		property int unitIndex: 0

		function gainUnitIndex() {
			if (internal.unitIndex + 1 > 5) {
				internal.unitIndex = 0;
			} else {
				internal.unitIndex++;
			}
		}

		function getUnit(unitIndex) {
			switch (unitIndex) {
			case 0: return "Time";
			case 1: return "Cup";
			case 2: return "Km";
			case 3: return "Page";
			case 4: return "Minute";
			case 5: return "Hour";
			}
		}
	}
}
