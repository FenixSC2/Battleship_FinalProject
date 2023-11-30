//
// Created by natha on 11/28/2023.
//

#include "../include/GameRunner.h"

GameRunner::GameRunner() {

}

GameRunner::GameRunner(int bs, int ns, vector<int> ss) {
    // initialize data
    boardSize = bs;
    numShips = ns;
    for (int i = 0; i < ns; i++) {
        shipSizes.emplace_back(ss[i]);
    }

    createShips();

    playerBoard = new GameBoard(boardSize, allShips, false);
    cpuBoard = new GameBoard(boardSize, allShips, true);
}

// play the game loop until the game is over
void GameRunner::play() {
    // set up the game TODO
    // have the player place their ships
    // placePlayerShips();
    // generation of locations for the CPU ships is done automatically

    // begin actual play of the game
    drawASCII(cpuBoard);
//    while(!isGameOver()) {
//        getPlayerMove();
//        getcpuMove();
//    }
}

IntPair GameRunner::getPlayerMove() {

}

IntPair GameRunner::getcpuMove() {

}

bool GameRunner::isGameOver() {
    // check if the game is over for either the player or the cpu
    if (playerBoard->isOver() || cpuBoard->isOver()) {
        return true;
    }
    return false;
}

void GameRunner::createShips() {
    int count = 0;
    for (int size : shipSizes) {
        allShips.emplace_back(new Ship(count, size));
        count++;
    }
}

void GameRunner::drawASCII(GameBoard* board) const {
    cout << "Drawing the grid" << endl;
    // create top border
    for (int i = 0; i < boardSize; i++) {
        cout << "--";
    }
    std::cout << "-" << std::endl;
    // create rows
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            std::cout << "|";
            if (board->getPos(IntPair(i, j)) == nullptr) {
                std::cout << " ";
            } else {
                std::cout << board->getPos(IntPair(i, j))->display();
            }
        }
        std::cout << "|" << std::endl;
    }
    // create bottom border
    for (int i = 0; i < boardSize; i++) {
        std::cout << "--";
    }
    std::cout << "-" << std::endl;
}
