//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_GAMEBOARD_H
#define BATTLESHIP_FINALPROJECT_GAMEBOARD_H

#include "ctime"
#include "Ship.h"

using namespace std;

class GameBoard {
private:
    int boardSize;
    vector<vector<Ship*>> board;
    vector<Ship*> ships;

    // initialize the board with all null values
    void initBoard();

    // set a single sell to point to a ship
    void setShip(IntPair location);

    // place all the ships randomly and legally on the board
    void setSail();

public:
    // constructors
    GameBoard();
    explicit GameBoard(int bs, vector<Ship*> allAvailableShips, bool placedRandomly);

    // rule of 3
    // Copy constructor
    GameBoard(const GameBoard& other);
    // Copy assignment operator
    GameBoard& operator=(const GameBoard& other);
    // Destructor
    ~GameBoard();

    // place an entire ship onto this board
    void placeShip(const vector<IntPair>& locations, Ship* ship);

    // determines if all ships on this board have sunk
    bool isOver();

    // get value at a position
    Ship* getPos(IntPair pair);
    // set a value at a position
    void setPos(IntPair pair, Ship* ship);

    // returns true if the input IntPair is on this board
    bool onBoard(IntPair pair) const;

    // determines if there is space at the given IntPair for a ship
    bool shipSpace(IntPair pair, int shipSize, bool isVertical, bool &directionLeftOrUp);

    /*
     * Function to hit a ship on the board
     * - returns true if a ship was hit AND removes the ship from that space
     * TODO: Make this space distinguishable as having been hit
     * - returns false if there was no ship present at the location
     *
     * Called on player and CPU turns as the main game mechanic
     */
    bool hit(IntPair pair);
};


#endif //BATTLESHIP_FINALPROJECT_GAMEBOARD_H
