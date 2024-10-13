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
        view/ViewV2.qml
        component_v2/UiConstant.qml
        component_v2/SidebarView.qml
        component_v2/ContentView.qml
        component_v2/DateFrame.qml
        component_v2/ContentHeader.qml

        view/ViewV1.qml
        component_v1/UiStyle.qml
        component_v1/CalendarHeader.qml
        component_v1/NoteBoard.qml
        component_v1/HabitBoard.qml
        component_v1/HabitDelegate.qml
        component_v1/ToolItem.qml
        component_v1/ToolPanel.qml
        component_v1/DayDelegate.qml
        component_v1/AddHabitPopup.qml
        component_v1/PokemonFrame.qml
        component_v1/ChoosePokemonPopup.qml
        component_v1/StatBar.qml
        component_v1/GradientFrame.qml
        component_v1/HabitTitle.qml
        component_v1/InfoTable.qml
    RESOURCES
        component_v2/qmldir
        assets_v2/leftdirection.svg
        assets_v2/rightdirection.svg
        assets_v2/option.svg

        component_v1/qmldir
        assets_v1/search.svg
        assets_v1/scrolldown.svg
        assets_v1/switch.svg
        assets_v1/jungle.png
        assets_v1/mpikachu.png
        assets_v1/fpikachu.png
        assets_v1/fest.png
        assets_v1/note.png
        assets_v1/leafeon.png
        assets_v1/lures.png
        assets_v1/incubator.png
        assets_v1/camera.png
        assets_v1/maxrevive.png
        assets_v1/egg.png
        assets_v1/incense.png
        assets_v1/twinkle.png
        assets_v1/binoculars.png
        assets_v1/razzberry.png
        assets_v1/goldenrazzberry.png
        assets_v1/pinapberry.png
        assets_v1/silverpinapberry.png
        assets_v1/nanabberry.png
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Quick)
