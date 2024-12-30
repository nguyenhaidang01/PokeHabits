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
        component/UiConstant.qml
        component/SidebarView.qml
        component/ContentView.qml
        component/DateFrame.qml
        component/ContentHeader.qml
        component/ContentFooter.qml
        component/PokemonFrame.qml
        component/ElementIcon.qml
        component/ElementFrame.qml
        component/HabitInfo.qml
        component/HabitDelegate.qml
        component/ProfileToolFrame.qml
        component/TitleFrame.qml
        component/TitleList.qml
        component/CreateListFrame.qml
        component/HabitEditorView.qml
        component/HeaderElement.qml
        component/TextWithPokeball.qml
        component/HabitEditorContent.qml
        component/PokeballDateDelegate.qml
        component/FrequencyDataField.qml
        component/SaveDischargeSelector.qml
        component/HabitNameDataField.qml
        component/PokemonDataField.qml
        component/TargetDataField.qml
        component/PokedexDelegate.qml
        component/PokedexPopup.qml
        component/HabitDetailView.qml
        component/HabitNameWithPoke.qml
        component/PokemonInfo.qml
        component/HabitStat.qml
        component/HabitStatsBoard.qml
        component/EvolChainBoard.qml
        component/MainViewLoader.qml
        component/CalendarPopup.qml

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
