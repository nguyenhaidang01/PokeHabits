cmake_minimum_required(VERSION 3.5)

project(PokeHabits VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Quick Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick Qml)

set(PROJECT_SOURCES
        main.cpp
)

set(LIB_LINKAGE 
    PRIVATE 
        UI
        core
)

set(CUSTOM_OUTPUT
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out
)

set(INCLUDE_DIR
    PUBLIC 
        ${CMAKE_CURRENT_BINARY_DIR}
)

include(CMakeFunc)

if(WIN32)
    set(GUI_TYPE WIN32)
elseif(APPLE)
    set(GUI_TYPE MACOSX_BUNDLE)
endif()

set(APP_ICON ${CMAKE_SOURCE_DIR}/assets/icon/icon.rc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    MakeExecute(
        ExeName PokeHabits
        ExecutableFiles ${PROJECT_SOURCES} ${APP_ICON}
        LinkLib ${LIB_LINKAGE}
        Definition
            PUBLIC 
        IncludeDirectory ${INCLUDE_DIR}
        TargetPro ${CUSTOM_OUTPUT}
    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

add_subdirectory(ui)

add_subdirectory(core)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJECT_NAME})
endif()


