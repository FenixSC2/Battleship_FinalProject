//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_GAMEBOARD_H
#define BATTLESHIP_FINALPROJECT_GAMEBOARD_H

#include "Ship.h"

using namespace std;

class GameBoard {
private:
    int boardSize;
    vector<vector<Ship*>> board;

    // initialize the board with all null values
    void initBoard();

    // set a single sell to point to a ship
    void setShip(IntPair location);

public:
    // constructor
    explicit GameBoard(int bs);

    // place an entire ship onto this board
    void placeShip(vector<IntPair> locations);
};


#endif //BATTLESHIP_FINALPROJECT_GAMEBOARD_H
