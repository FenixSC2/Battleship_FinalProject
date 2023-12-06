cmake_minimum_required(VERSION 3.26)
project(Battleship_FinalProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Add the Matplot++ subdirectory to your project
add_subdirectory(matplotplusplus)

# Define your game executable with all source files
add_executable(Battleship_FinalProject main.cpp
        lib/src/GameBoard.cpp
        lib/include/GameBoard.h
        lib/src/Ship.cpp
        lib/include/Ship.h
        lib/src/GameRunner.cpp
        lib/include/GameRunner.h
        lib/src/IntPair.cpp
        lib/include/IntPair.h
        lib/src/AudioPlayer.cpp)

# Link Matplot++ to your game executable
target_link_libraries(Battleship_FinalProject PUBLIC matplot)
