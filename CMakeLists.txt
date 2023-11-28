cmake_minimum_required(VERSION 3.26)
project(Battleship_FinalProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(Battleship_FinalProject main.cpp
        lib/src/GameBoard.cpp
        lib/include/GameBoard.h
        lib/src/Ship.cpp
        lib/include/Ship.h
        lib/src/GameRunner.cpp
        lib/include/GameRunner.h
        lib/src/IntPair.cpp
        lib/include/IntPair.h)
