/******************************************************************************
**
** File      PokedexPopup.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component_v2"

Popup {
	id: root

	width: internal.defaultPopupWidth
	height: internal.defaultPopupHeight

	modal: true
	focus: true

	background: Rectangle { color: internal.backgroundColor }

	ColumnLayout {
		anchors.fill: parent

		Rectangle {
			Layout.preferredWidth: 310
			Layout.preferredHeight: 60

			Layout.alignment: Qt.AlignHCenter
			Layout.topMargin: 40

			radius: internal.radius
			border.width: internal.borderWidth

			RowLayout {
				anchors.fill: parent

				Image {
					width: internal.pokeballSize
					height: internal.pokeballSize
					Layout.leftMargin: 10

					source: internal.pokeballUrl
				}

				Text {
					Layout.leftMargin: 15

					font {
						pixelSize: 21
						family: "Inter"
					}

					text: "SEARCH"
				}

				Item {
					Layout.fillWidth: true
					Layout.fillHeight: true
				}

				Image {
					width: internal.searchSize
					height: internal.searchSize
					Layout.rightMargin: 5

					source: internal.searchUrl
				}
			}
		}

		GridView {
			id: pokedex

			Layout.preferredWidth: internal.pokedexSize
			Layout.preferredHeight: internal.pokedexSize

			Layout.alignment: Qt.AlignHCenter

			cellWidth: internal.pokedexEntrySize
			cellHeight: internal.pokedexEntrySize

			clip: true
			model: 9

			delegate: PokedexDelegate {}
		}
	}

	Image {
		id: close

		width: internal.closeSize
		height: internal.closeSize

		anchors {
			top: parent.top
			right: parent.right
			topMargin: 5
			rightMargin: 5
		}

		source: internal.closeUrl

		MouseArea {
			anchors.fill: parent
			onClicked: function() {
				root.close();
			}
		}
	}

	QtObject {
		id: internal

		readonly property int defaultPopupWidth: 840
		readonly property int defaultPopupHeight: 922

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property int pokedexSize: 720
		readonly property int pokedexEntrySize: 240

		readonly property int pokeballSize: 35
		readonly property int searchSize: 30
		readonly property int closeSize: 45

		readonly property string pokeballUrl: "qrc:/ui/assets_v2/pokeball.svg"
		readonly property string searchUrl: "qrc:/ui/assets_v2/bigsearch.svg"
		readonly property string closeUrl: "qrc:/ui/assets_v2/close.svg"

		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
