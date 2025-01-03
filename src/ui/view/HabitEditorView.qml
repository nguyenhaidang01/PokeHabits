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

	property QtObject model: null //HabitModel
	property QtObject controller: null

	property int editIndex
	property QtObject pokemonModel: null //PokemonModel

	color: internal.backgroundColor

	ColumnLayout {
		anchors.fill: parent

		HeaderElement {
			id: header

			Layout.fillWidth: true
			Layout.preferredHeight: internal.headerHeight

			elementName: root.editIndex !== internal.appendIndex ?
							 internal.pokemonHelper.firstType(internal.editHabit.pokeId) :
							 internal.defaultElementName

			onExitView: function() {
				internal.uiService.changeToPreviousView();
			}
		}

		HabitEditorContent {
			id: habitEditorContent

			Layout.fillWidth: true
			Layout.fillHeight: true

			editIndex: root.editIndex
			pokedexPopup: pokedexPopup

			model: root.model
			controller: root.controller
		}
	}

	PokedexPopup {
		id: pokedexPopup

		width: internal.pokedexPopupWidth
		height: internal.pokedexPopupHeight

		anchors.centerIn: parent

		model: root.pokemonModel
	}

	QtObject {
		id: internal

		readonly property int appendIndex: -1
		readonly property string defaultElementName: "grass"

		property var editHabit: root.editIndex !== appendIndex ?
									    root.model.get(root.editIndex) : null
		property QtObject uiService: root.controller ? root.controller.uiService : null
		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null

		readonly property int circleHeaderSize: 2000
		readonly property int headerHeight: 222

		readonly property int pokedexPopupWidth: 840
		readonly property int pokedexPopupHeight: 922

		readonly property color backgroundColor: UiConstant.pureWhite
	}
}
