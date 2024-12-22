/******************************************************************************
**
** File      HabitEditorView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import "../component"

Rectangle {
	id: root

	property QtObject pokemonModel: null
	property QtObject controller: null

	color: internal.backgroundColor

	ColumnLayout {
		anchors.fill: parent

		HeaderElement {
			id: header

			Layout.fillWidth: true
			Layout.preferredHeight: internal.headerHeight

			onExitView: function() {
				internal.uiService.changeToPreviousView();
			}
		}

		HabitEditorContent {
			id: habitEditorContent

			Layout.fillWidth: true
			Layout.fillHeight: true

			controller: root.controller
			pokedexPopup: pokedexPopup
		}
	}

	PokedexPopup {
		id: pokedexPopup

		width: internal.pokedexPopupWidth
		height: internal.pokedexPopupHeight

		anchors.centerIn: parent

		pokemonModel: root.pokemonModel
	}

	QtObject {
		id: internal

		property QtObject uiService: root.controller ? root.controller.uiService : null

		readonly property int circleHeaderSize: 2000
		readonly property int headerHeight: 222

		readonly property int pokedexPopupWidth: 840
		readonly property int pokedexPopupHeight: 922

		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
