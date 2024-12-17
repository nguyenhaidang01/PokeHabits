project(core)

set(SOURCES 
    ViewController.h ViewController.cpp
    PokeHabitsApp.h PokeHabitsApp.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Concurrent Sql)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick Qt6::Concurrent Qt6::Sql
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
