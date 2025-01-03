/******************************************************************************
**
** File      EvolChainBoard.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Item {
	id: root

	property QtObject controller: null
	property int pokeId

	ColumnLayout {
		anchors.fill: parent

		Text {
			Layout.alignment: Qt.AlignTop

			font {
				pixelSize: 32
				weight: Font.Medium
				family: "Poppins"
			}

			text: "Evolution"
		}

		Rectangle {
			Layout.fillWidth: true
			Layout.preferredHeight: 200

			Layout.alignment: Qt.AlignBottom

			radius: internal.radius
			border.width: internal.borderWidth

			Item {
				implicitWidth: 705
				implicitHeight: 145

				anchors.centerIn: parent

				RowLayout {
					anchors.fill: parent

					PokemonFrame {
						Layout.alignment: Qt.AlignLeft

						pokeImage: internal.pokeImage
						pokeType: internal.pokeType
					}

					Item {
						Layout.fillWidth: true
						Layout.fillHeight: true

						ColumnLayout {
							implicitWidth: 60
							implicitHeight: 65

							anchors.centerIn: parent

							Text {
								font {
									pixelSize: 16
									weight: Font.Medium
									family: "Poppins"
								}

								color: internal.textColor
								text: "Level " +  internal.defaultFirstEvoLvl
							}

							Image {
								width: internal.arrowWidth
								height: internal.arrowHeight

								Layout.alignment: Qt.AlignHCenter
								source: internal.arrowUrl
							}
						}
					}

					PokemonFrame {
						Layout.alignment: Qt.AlignHCenter

						pokeImage: internal.pokeImage
						pokeType: internal.pokeType
					}

					Item {
						Layout.fillWidth: true
						Layout.fillHeight: true

						ColumnLayout {
							implicitWidth: 60
							implicitHeight: 65

							anchors.centerIn: parent

							Text {
								font {
									pixelSize: 16
									weight: Font.Medium
									family: "Poppins"
								}

								color: internal.textColor
								text: "Level " + internal.defaultSecondEvoLvl
							}

							Image {
								width: internal.arrowWidth
								height: internal.arrowHeight

								Layout.alignment: Qt.AlignHCenter
								source: internal.arrowUrl
							}
						}
					}

					PokemonFrame {
						Layout.alignment: Qt.AlignRight

						pokeImage: internal.pokeImage
						pokeType: internal.pokeType
					}
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property int radius: 15
		readonly property real borderWidth: 0.5

		readonly property color textColor: "#173EA5"

		readonly property int defaultFirstEvoLvl: 16
		readonly property int defaultSecondEvoLvl: 32

		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null
		property string pokeImage: internal.pokemonHelper.image(root.pokeId)
		property string pokeType: internal.pokemonHelper.firstType(root.pokeId)

		readonly property int arrowWidth: 24
		readonly property int arrowHeight: 37
		readonly property string arrowUrl: "qrc:/ui/assets/bluerightarrow.svg"
		readonly property string defaultElementUrl: "qrc:/ui/assets/grass.svg"
		readonly property string defaultPokemonUrl: "qrc:/ui/assets/bulbasaur.svg"
		readonly property string defaultPokemonFirstType: "grass"
	}
}
