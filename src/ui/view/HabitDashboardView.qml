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

	property QtObject model: null //HabitModel
	property QtObject controller: null
	property QtObject calendarModel: null //CalendarModel

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

			date: internal.selectedDate

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
			model: root.model

			delegate: HabitDelegate {
				visible: isExist
				implicitWidth: internal.habitDelegateWidth
				implicitHeight: 145

				habitName: name
				doneStatus: done
				exp: pokeExp
				pokeName: internal.pokemonHelper.name(pokeId)
				pokeImage: internal.pokemonHelper.image(pokeId)
				pokeBaseExp: internal.pokemonHelper.baseExp(pokeId)

				onOpenDetailHabit: function() {
					root.model.selectedHabitIndex = index;
					internal.uiService.changeToHabitDetailView();
				}

				onRequestChangeDoneStatus: function(status) {
					if (internal.selectedDate !== internal.currentDate) {
						return
					}
					root.model.toggleDoneStatus(index, internal.selectedDate);
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

		model: root.calendarModel
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

		property string currentDate: root.calendarModel.currentDateStr
		property string selectedDate: root.calendarModel.selectedDateStr

		property QtObject uiService: root.controller ? root.controller.uiService : null
		property QtObject pokemonHelper: root.controller ? root.controller.pokemonHelper : null
	}
}
