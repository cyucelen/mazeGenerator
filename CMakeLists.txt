cmake_minimum_required(VERSION 3.7)
project(mazeGenerator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cell.cpp Cell.h global.cpp global.h)
add_executable(mazeGenerator ${SOURCE_FILES})
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )
target_link_libraries( mazeGenerator ${CURSES_LIBRARIES} )