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
        component/CalendarHeader.qml
        component/NoteBoard.qml
        component/HabitBoard.qml
        component/HabitDelegate.qml
        component/ToolItem.qml
        component/ToolPanel.qml
    RESOURCES
        component/qmldir
        assets/Jungle.png
        assets/mPikachu.png
        assets/fPikachu.png
        assets/PokemonFest.png
        assets/NoteIcon.png
        assets/Leafeon.png
        assets/Scythe.png
        assets/Lures.png
        assets/EggDistance.png
        assets/Camera.png
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Quick)
