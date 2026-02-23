cmake_minimum_required(VERSION 3.10.0)
project(ncurses_game VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O1 -Wall -Wextra -Wpedantic -Wformat -Wshadow -Wconversion -Wsign-conversion")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-strong -D_FORTIFY_SOURCE=2 -fPIC")

find_package(Curses REQUIRED)
include_directories(include lib)

file (GLOB_RECURSE SOURCES
    "src/main.cpp"
    "lib/extra_class/*.cpp"
    "lib/environment_class/*.cpp"
    "lib/move_obj_class/*.cpp"
    "lib/move_obj_class/npc_child_class/*.cpp"
)
add_executable(ncurses_game  ${SOURCES})

target_include_directories(ncurses_game PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(ncurses_game ${CURSES_LIBRARIES})