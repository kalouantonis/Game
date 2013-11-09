cmake_minimum_required(VERSION 2.8)

project(game)

set(SOURCE
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
)

add_executable(game ${SOURCE})

add_subdirectory(Utils)
add_subdirectory(GO)
add_subdirectory(Math)
add_subdirectory(Input)
# Link my libraries
target_link_libraries(game Utils)
target_link_libraries(game GO)
target_link_libraries(game Math)
target_link_libraries(game Input)



# Use C++11
add_definitions(-std=c++11)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(game ${SDL2_LIBRARIES})

install(TARGETS game RUNTIME DESTINATION bin)

add_subdirectory(Logic)
