project(core)

set(SOURCES
	Pokemon.h Habit.h
	CalendarModel.h CalendarModel.cpp
	HabitModel.h HabitModel.cpp
	PokemonModel.h PokemonModel.cpp
	PokemonHelper.h PokemonHelper.cpp
	PokeApiService.h PokeApiService.cpp
	UiService.h UiService.cpp
	PokeHabitsController.h PokeHabitsController.cpp
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
