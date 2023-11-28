//
// Created by natha on 11/28/2023.
//

#include "../include/GameRunner.h"

GameRunner::GameRunner(int boardSize, int numShips, int shipSizes[numShips]) {
    // initialize data
}

// play the game loop until the game is over
void GameRunner::play() {
    // set up the game TODO
    // have the player place their ships
    // generate locations for the CPU ships

    // begin actual play of the game
    while(!isGameOver()) {
        playerMove();
        cpuMove();
    }
}

void GameRunner::playerMove() {

}

void GameRunner::cpuMove() {

}

bool GameRunner::isGameOver() {
    return false;
}
