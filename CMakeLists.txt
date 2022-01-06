cmake_minimum_required(VERSION 3.16)
project(Chess)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pedantic-errors -pthread")

add_executable(Chess
        src/drawer/drawer.cpp
        src/game/game.cpp
        src/chess/chess.cpp
        src/main.cpp
)

target_link_libraries(Chess SDL2 SDL2_image)