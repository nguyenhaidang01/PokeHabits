/******************************************************************************
**
** File      ContentView.qml
** Author    Dang Nguyen
**
******************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../component"

Rectangle {
	id: root

	property QtObject controller: null
	property QtObject habitModel: null

	color: internal.backgroundColor

	ColumnLayout {
		id: contentLayout

		anchors.fill: parent
		anchors.margins: internal.contentMargin

		spacing: 0

		ContentHeader {
			id: contentHeader

			Layout.fillWidth: true
			Layout.preferredHeight: 60

			calendarModel: internal.calendarModel

			onOpenCalendarPopup: function() {
				calendarPopup.open();
			}
		}

		Item {
			Layout.fillWidth: true
			Layout.preferredHeight: 20
		}

		ListView {
			Layout.fillWidth: true
			Layout.fillHeight: true

			clip: true

			spacing:24
			model: root.habitModel

			delegate: HabitDelegate {
				implicitWidth: internal.habitDelegateWidth
				implicitHeight: 145

				habitName: name
				pokemonName: internal.pokemonHelper.pokemonName(pokeId)
				pokemonImage: internal.pokemonHelper.pokemonImage(pokeId)
				baseExp: internal.pokemonHelper.pokemonBaseExp(pokeId)
				exp: root.habitModel.get(index).pokeExp

				MouseArea {
					anchors.fill: parent
					onClicked: function() {
						root.habitModel.selectedHabitIndex = index;
						internal.uiService.changeToHabitDetailView();
					}
				}
			}
		}

		ContentFooter {
			id: contentFooter

			Layout.fillWidth: true
			Layout.preferredHeight: 112

			MouseArea {
				anchors.fill: parent
				onClicked: function() {
					internal.uiService.changeToHabitEditorView(internal.appendIndex);
				}
			}
		}
	}

	CalendarPopup {
		id: calendarPopup

		topMargin: internal.calendarPopupTopMargin
		leftMargin: internal.calendarPopupLeftMargin

		controller: root.controller
	}

	QtObject {
		id: internal

		readonly property int appendIndex: -1

		readonly property int contentMargin: 60
		readonly property int habitDelegateWidth: root.width - 2 * contentMargin

		readonly property int calendarPopupWidth: 518
		readonly property int calendarPopupHeight: 535

		readonly property int sidebarWidth: 350

		readonly property int calendarPopupTopMargin: 60
		readonly property int calendarPopupLeftMargin: (root.width - calendarPopupWidth)/2 + sidebarWidth

		readonly property color backgroundColor: UiConstant.pureWhite

		property QtObject uiService: root.controller ? root.controller.uiService : null
		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null
		property QtObject calendarModel: root.controller ? root.controller.calendarModel : null
	}
}
