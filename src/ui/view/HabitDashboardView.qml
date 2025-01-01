/******************************************************************************
**
** File      HabitDashboardView.qml
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
		id: dashboardLayout

		anchors.fill: parent
		anchors.margins: internal.dashboardMargin

		spacing: 0

		DashboardHeader {
			id: dashboardHeader

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
				visible: isExist
				implicitWidth: internal.habitDelegateWidth
				implicitHeight: 145

				habitName: name
				doneStatus: done
				exp: pokeExp
				pokeName: internal.pokemonHelper.pokemonName(pokeId)
				pokeImage: internal.pokemonHelper.pokemonImage(pokeId)
				pokeBaseExp: internal.pokemonHelper.pokemonBaseExp(pokeId)

				onOpenDetailHabit: function() {
					root.habitModel.selectedHabitIndex = index;
					internal.uiService.changeToHabitDetailView();
				}

				onRequestChangeDoneStatus: function(status) {
					var currentDateStr = internal.calendarModel.currentDateStr;
					var selectedDateStr = internal.selectedDateStr;
					if (selectedDateStr === currentDateStr) {
						root.habitModel.toggleDoneStatus(index, selectedDateStr);
					}
				}
			}
		}

		DashboardFooter {
			id: dashboardFooter

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

		readonly property int dashboardMargin: 60
		readonly property int habitDelegateWidth: root.width - 2 * dashboardMargin

		readonly property int calendarPopupWidth: 518
		readonly property int calendarPopupHeight: 535

		readonly property int sidebarWidth: 350

		readonly property int calendarPopupTopMargin: 60
		readonly property int calendarPopupLeftMargin: (root.width - calendarPopupWidth)/2 + sidebarWidth

		readonly property color backgroundColor: UiConstant.pureWhite

		property QtObject uiService: root.controller ? root.controller.uiService : null
		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null
		property QtObject calendarModel: root.controller ? root.controller.calendarModel : null

		property string selectedDateStr: internal.calendarModel.selectedDateStr
	}
}
