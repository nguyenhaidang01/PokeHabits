project(core)

set(SOURCES 
    Pokemon.h
    PokemonList.h PokemonList.cpp
    PokemonModel.h PokemonModel.cpp
    PokeApiManager.h PokeApiManager.cpp
    DailyReportList.h DailyReportList.cpp
    DailyReportModel.h DailyReportModel.cpp
    PokeHabitsApp.h PokeHabitsApp.cpp
    CalendarList.h CalendarList.cpp
    CalendarModel.h CalendarModel.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Concurrent)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick Qt6::Concurrent
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
