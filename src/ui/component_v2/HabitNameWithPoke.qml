/******************************************************************************
**
** File      HabitNameWithPoke.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Item {
	id: root

	property string habitName
	property string pokemonUrl

	signal openEditorView()

	implicitHeight: internal.defaultHeight

	ColumnLayout {
		anchors.fill: parent

		Item {
			id: pokemon

			Layout.preferredWidth: internal.pokemonSize
			Layout.preferredHeight: internal.pokemonSize

			Layout.alignment: Qt.AlignHCenter

			Image {
				anchors.fill: parent
				source: root.pokemonUrl
			}
		}

		Item {
			id: habitName

			Layout.fillWidth: true
			Layout.preferredHeight: 48

			RowLayout {
				anchors.fill: parent

				Item {
					Layout.fillWidth: true
					Layout.fillHeight: true
				}

				Item {
					Layout.preferredWidth: 30
					Layout.fillHeight: true
				}

				Text {
					Layout.alignment: Qt.AlignHCenter

					font {
						pixelSize: 32
						weight: Font.Medium
						family: "Poppins"
					}

					verticalAlignment: Text.AlignVCenter
					text: root.habitName
				}

				Image {
					id: edit

					width: internal.editSize
					height: internal.editSize

					source: internal.editUrl

					MouseArea {
						anchors.fill: parent
						onClicked: function() {
							root.openEditorView();
						}
					}
				}

				Item {
					Layout.fillWidth: true
					Layout.fillHeight: true
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property int defaultHeight: 205

		readonly property int editSize: 30
		readonly property int pokemonSize: 150

		readonly property string editUrl: "qrc:/ui/assets_v2/pen.svg"
	}
}
