project(core)

set(SOURCES 
    Pokemon.h
    PokemonList.h PokemonList.cpp
    PokemonModel.h PokemonModel.cpp
    PokeHabitsApp.h PokeHabitsApp.cpp
    CalendarList.h CalendarList.cpp
    CalendarModel.h CalendarModel.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
