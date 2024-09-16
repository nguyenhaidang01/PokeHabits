project(core)

set(SOURCES 
    Pokemon.h
    PokemonList.h PokemonList.cpp
    PokemonModel.h PokemonModel.cpp
    DailyReportList.h DailyReportList.cpp
    DailyReportModel.h DailyReportModel.cpp
    CalendarList.h CalendarList.cpp
    CalendarModel.h CalendarModel.cpp
    PokeApiManager.h PokeApiManager.cpp
    DatabaseManager.h DatabaseManager.cpp
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
