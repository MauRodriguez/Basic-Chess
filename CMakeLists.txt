cmake_minimum_required(VERSION 3.16)
project(Chess)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g -pedantic-errors -pthread")

add_executable(chess
        src/drawer/drawer.cpp
        src/drawer/mbutton.cpp

        src/game/game.cpp

        src/chess/chess.cpp
        src/chess/piece.cpp
        src/main.cpp
)

target_link_libraries(chess SDL2 SDL2_image)