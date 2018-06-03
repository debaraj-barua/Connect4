cmake_minimum_required(VERSION 2.8)

project( Connect4 )

set(CMAKE_BUILD_TYPE Debug)

add_definitions(-std=c++11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

include_directories (
    include
)

add_executable( Connect4
        	src/main.cpp
            src/Players.cpp
            src/GameBoard.cpp)
