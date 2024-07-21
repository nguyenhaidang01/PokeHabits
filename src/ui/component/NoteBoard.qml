/******************************************************************************
**
** File      NoteBoard.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	implicitWidth: 1014
	implicitHeight: 160

	clip: true

	property QtObject model: null

	Image {
		id: background

		width: 1014
		height: 520

		opacity: 0.4
		source: "qrc:/ui/assets/Jungle.png"
	}

	RowLayout {
		implicitWidth: 965
		implicitHeight: 136

		anchors {
			verticalCenter: parent.verticalCenter
			left: parent.left
			leftMargin: 19
		}

		spacing: 35

		Item {
			id: sectionHeader

			implicitWidth: 316
			implicitHeight: 136

			Image {
				id: logo

				width: 138
				height: 136

				source: "qrc:/ui/assets/PokemonFest.png"
			}

			Rectangle {
				id: noteLabel

				implicitWidth: 130
				implicitHeight: 35

				anchors {
					bottom: parent.bottom
					right: parent.right
					rightMargin: 34
				}

				radius: 12

				Label {
					anchors.centerIn: parent

					font {
						bold: true
						pixelSize: 18
					}
					color: "#2F5B4B"
					text: "Note"
				}
			}

			Image {
				id: fPikachu

				width: 92
				height: 106
				anchors.right: parent.right

				source: "qrc:/ui/assets/fPikachu.png"
			}

			Image {
				id: mPikachu

				width: 102
				height: 104
				anchors.right: fPikachu.left

				source: "qrc:/ui/assets/mPikachu.png"
			}
		}

		Item {
			id: noteContent

			implicitWidth: 614
			implicitHeight: 136

			Rectangle {
				id: noteFrame

				implicitWidth: 586
				implicitHeight: 125

				anchors {
					right: parent.right
					bottom: parent.bottom
				}

				radius: 12

				Label {
					anchors.centerIn: parent

					font {
						bold: true
						italic: true
						pixelSize: 18
					}
					color: "#701C1C"
					opacity: 0.87
					text: root.model? root.model : internal.defaultNote
				}
			}

			Image {
				id: noteIcon

				width: 56
				height: 56

				source: "qrc:/ui/assets/NoteIcon.png"
			}
		}
	}

	QtObject {
		id: internal

		property string defaultNote: "SIUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"
	}
}
