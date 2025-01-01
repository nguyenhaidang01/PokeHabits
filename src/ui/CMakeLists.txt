project(UI)

find_package(Qt6 COMPONENTS Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set_source_files_properties(
    view/Main.qml
    PROPERTIES
    QT_RESOURCE_ALIAS Main.qml
)

add_library(${PROJECT_NAME} STATIC)

qt6_add_qml_module(${PROJECT_NAME}
    URI "ui"
    VERSION 1.0
    RESOURCE_PREFIX "/"
    NO_PLUGIN
    NO_GENERATE_QMLTYPES
    QML_FILES
	view/Main.qml
	view/MainView.qml
	view/SidebarView.qml
	view/HabitDashboardView.qml
	view/HabitEditorView.qml
	view/HabitDetailView.qml

	component/UiConstant.qml
	component/MainViewLoader.qml
	
	# SidebarView component
		component/ProfileToolFrame.qml
		component/TitleList.qml
			component/TitleFrame.qml
		component/CreateListFrame.qml
	
	# HabitDashboardView component
		component/DashboardHeader.qml
			component/DateFrame.qml
		component/HabitDelegate.qml 
			component/PokemonFrame.qml
			component/HabitInfo.qml
				component/ElementFrame.qml
					component/ElementIcon.qml
		component/DashboardFooter.qml
		component/CalendarPopup.qml

	# HabitEditorView component
		component/HeaderElement.qml
		component/HabitEditorContent.qml
			component/PokemonDataField.qml
				component/TextWithPokeball.qml
			component/HabitNameDataField.qml
			component/TargetDataField.qml
			component/FrequencyDataField.qml
				component/PokeballDateDelegate.qml	
			component/SaveDischargeSelector.qml
		component/PokedexPopup.qml
			component/PokedexDelegate.qml

	# HabitEditorView component
		# component/HeaderElement.qml	
		component/PokemonInfo.qml
			# component/ElementFrame.qml
		component/HabitStatsBoard.qml
			component/HabitStat.qml
		component/EvolChainBoard.qml
			# component/PokemonFrame.qml
		component/HabitNameWithPoke.qml
	
    RESOURCES
	component/qmldir
	assets/leftdirection.svg
	assets/rightdirection.svg
	assets/option.svg
	assets/favorite.svg
	assets/done.svg
	assets/search.svg
	assets/bigsearch.svg
	assets/add.svg
	assets/squareAdd.svg
	assets/leftarrow.svg
	assets/blackleftarrow.svg
	assets/blackrightarrow.svg
	assets/bluerightarrow.svg
	assets/lightfavorite.svg
	assets/pen.svg
	assets/nochange.svg
	assets/save.svg
	assets/discharge.svg
	assets/close.svg
	assets/pokeball.svg
	assets/nocolorpokeball.svg
	assets/bulbasaur.svg
	assets/normal.svg
	assets/fire.svg
	assets/water.svg
	assets/electric.svg
	assets/grass.svg
	assets/ice.svg
	assets/fighting.svg
	assets/poison.svg
	assets/ground.svg
	assets/flying.svg
	assets/psychic.svg
	assets/bug.svg
	assets/rock.svg
	assets/ghost.svg
	assets/dragon.svg
	assets/dark.svg
	assets/steel.svg
	assets/fairy.svg
	assets/normalColor.svg
	assets/fireColor.svg
	assets/waterColor.svg
	assets/electricColor.svg
	assets/grassColor.svg
	assets/iceColor.svg
	assets/fightingColor.svg
	assets/poisonColor.svg
	assets/groundColor.svg
	assets/flyingColor.svg
	assets/psychicColor.svg
	assets/bugColor.svg
	assets/rockColor.svg
	assets/ghostColor.svg
	assets/dragonColor.svg
	assets/darkColor.svg
	assets/steelColor.svg
	assets/fairyColor.svg
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Quick)
