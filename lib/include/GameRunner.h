//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_GAMERUNNER_H
#define BATTLESHIP_FINALPROJECT_GAMERUNNER_H

#include "GameBoard.h"
#include "iostream"

using namespace std;

class GameRunner {
private:
    // data
    int boardSize, numShips;
    vector<int> shipSizes;
    vector<Ship*> allShips;
    // boards for the player and cpu
    GameBoard* playerBoard;
    GameBoard* cpuBoard;

    // for player moves
    // gets the location the player would like to hit
    IntPair getPlayerMove();

    // for computer moves
    // get the location the cpu selected to hit (TODO: randomly generated probably)
    IntPair getcpuMove();

    // for determining if the game has concluded
    bool isGameOver();

    // create the ships for the game to be used by the player and CPU
    void createShips();

    // create an ASCII representation of the board
    void drawASCII(GameBoard* board) const;

public:
    // constructors
    GameRunner();
    GameRunner(int boardSize, int numShips, vector<int> shipSizes);

    // start and run the game
    void play();
};


#endif //BATTLESHIP_FINALPROJECT_GAMERUNNER_H
