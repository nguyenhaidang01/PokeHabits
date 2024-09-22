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
        component/UiStyle.qml
        component/CalendarHeader.qml
        component/NoteBoard.qml
        component/HabitBoard.qml
        component/HabitDelegate.qml
        component/ToolItem.qml
        component/ToolPanel.qml
        component/DayDelegate.qml
        component/AddHabitPopup.qml
        component/PokemonFrame.qml
        component/ChoosePokemonPopup.qml
        component/StatBar.qml
        component/GradientFrame.qml
    RESOURCES
        component/qmldir
        assets/jungle.png
        assets/mpikachu.png
        assets/fpikachu.png
        assets/fest.png
        assets/note.png
        assets/leafeon.png
        assets/search.svg
        assets/lures.png
        assets/incubator.png
        assets/camera.png
        assets/maxrevive.png
        assets/scrolldown.svg
        assets/egg.png
        assets/incense.png
        assets/twinkle.png
        assets/binoculars.png
        assets/razzberry.png
        assets/goldenrazzberry.png
        assets/pinapberry.png
        assets/silverpinapberry.png
        assets/nanabberry.png
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Quick)
