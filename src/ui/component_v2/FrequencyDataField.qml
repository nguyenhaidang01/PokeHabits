/******************************************************************************
**
** File      FrequencyDataField.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

RowLayout {
	id: root

	spacing: 0

	states: [
		State {
			name: "general"; when: !internal.displayDetail
			PropertyChanges { target: generalFrequency; visible: true }
			PropertyChanges { target: detailFrequency; visible: false }
		},
		State {
			name: "detail"; when: internal.displayDetail
			PropertyChanges { target: generalFrequency; visible: false }
			PropertyChanges { target: detailFrequency; visible: true }
		}
	]

	Item {
		Layout.preferredWidth: 317
		Layout.fillHeight: true

		TextWithPokeball {
			anchors.verticalCenter: parent.verticalCenter
			text: "FREQUENCY"
		}
	}

	Rectangle {
		id: generalFrequency

		Layout.fillWidth: true
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

			text: "Everyday"
		}

		Image {
			width: 49
			height: 60
			anchors.right: parent.right

			source: "qrc:/ui/assets_v2/blackleftarrow.svg"

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					internal.displayDetail = !internal.displayDetail;
				}
			}
		}
	}

	Rectangle {
		id: detailFrequency

		Layout.fillWidth: true
		Layout.fillHeight: true

		radius: internal.radius
		border.width: internal.borderWidth

		RowLayout {
			anchors.fill: parent

			spacing: 0

			Item {
				Layout.fillWidth: true
				Layout.fillHeight: true
			}

			ListView {
				Layout.preferredWidth: 455
				Layout.preferredHeight: 53

				Layout.alignment: Qt.AlignVCenter

				orientation: ListView.Horizontal
				spacing: 35

				model: dayOfWeekModel
				delegate: PokeballDateDelegate{ dayOfWeek: day }
			}

			Image {
				Layout.preferredWidth: 49
				Layout.preferredHeight: 60

				source: "qrc:/ui/assets_v2/blackrightarrow.svg"

				MouseArea {
					anchors.fill: parent
					onClicked: function() {
						internal.displayDetail = !internal.displayDetail;
					}
				}
			}
		}
	}

	ListModel {
		id: dayOfWeekModel

		ListElement { day: "SUN" }
		ListElement { day: "MON" }
		ListElement { day: "TUE" }
		ListElement { day: "WED" }
		ListElement { day: "THUR" }
		ListElement { day: "FRI" }
		ListElement { day: "SAT" }
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		property bool displayDetail: false
	}
}
