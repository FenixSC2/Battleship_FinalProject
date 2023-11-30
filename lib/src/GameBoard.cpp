//
// Created by natha on 11/28/2023.
//

#include "../include/GameBoard.h"

GameBoard::GameBoard() {

}

GameBoard::GameBoard(int bs, vector<Ship*> s, bool placedRandomly) {
    boardSize = bs;
    ships = s;

    initBoard();

    if (placedRandomly) {
        setSail();
    }
}

// initialize the game board
void GameBoard::initBoard() {
    // resize the board to the specified size and fill with nullptrs
    board.resize(boardSize, vector<Ship*>(boardSize, nullptr));
    // set the random seed using time
    std::srand(std::time(0));
}

void GameBoard::setSail() {
    // pick a random location and orientation for each ship and place it on the board
    for (Ship* s : ships) {
        bool foundSpot = false;
        // flip a coin for vertical or horizontal ship
        bool isVertical = true;
        if (rand() % 2 == 0) {
            isVertical = !isVertical;
        }
        // loop here in case the random position selected is occupied
        do {
            // get new random position on board
            int x = rand() % boardSize;
            int y = rand() % boardSize;
            // initialize value to know where to place the ship
            bool directionRightOrDown;
            // confirm that we are on the board
            IntPair pair = IntPair(x, y);
            if (onBoard(pair)) {
                // determine if the ship can be placed (e.g. is there enough space)
                if (shipSpace(pair, s->getSize(), isVertical, directionRightOrDown)) {
                    // if the ship can be placed, place it and update foundSpot
                    vector<IntPair> locations;
                    // populate locations
                    for (int i = 0; i < s->getSize(); i++) {
                        if (isVertical) {
                            if (directionRightOrDown) {
                                locations.emplace_back(IntPair(pair.getX(), pair.getY() + i));
                            } else {
                                locations.emplace_back(IntPair(pair.getX(), pair.getY() - i));
                            }
                        } else {
                            if (directionRightOrDown) {
                                locations.emplace_back(IntPair(pair.getX() + i, pair.getY()));
                            } else {
                                locations.emplace_back(IntPair(pair.getX() - i, pair.getY()));
                            }
                        }
                    }
                    // place the ship on the board at the proper locations
                    placeShip(locations, s);
                    // update the loop
                    foundSpot = true;
                }
            }
        } while (!foundSpot);
    }
}

GameBoard::GameBoard(const GameBoard &other) {
    // Copy the board size
    boardSize = other.boardSize;

    // Deep copy the ships vector
    ships = other.ships;

    // Initialize the board
    initBoard();

    // Copy the content of the board
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // Check if the cell in 'other' has a ship
            if (other.board[i][j] != nullptr) {
                // Create a new ship with the same type
                board[i][j] = new Ship(*(other.board[i][j]));
            }
        }
    }
}

GameBoard &GameBoard::operator=(const GameBoard &other) {
    if (this != &other) { // Check for self-assignment
        // Release resources of the current object
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                delete board[i][j];
            }
        }

        // Copy the board size
        boardSize = other.boardSize;

        // Deep copy the ships vector
        ships = other.ships;

        // Initialize the board
        initBoard();

        // Copy the content of the board
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                // Check if the cell in 'other' has a ship
                if (other.board[i][j] != nullptr) {
                    // Create a new ship with the same type
                    board[i][j] = new Ship(*(other.board[i][j]));
                }
            }
        }
    }
    return *this;
}

GameBoard::~GameBoard() {
    // Release resources of the board
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            delete board[i][j];
        }
    }
}

bool GameBoard::isOver() {
    bool gate = true;
    for (Ship* sh : ships) {
        gate = gate && sh->isSunk();
    }
    return gate;
}

Ship *GameBoard::getPos(IntPair pair) {
    return board[pair.getX()][pair.getY()];
}

bool GameBoard::onBoard(IntPair pair) const {
    return (pair.getX() >= 0 && pair.getX() < boardSize) && (pair.getY() >= 0 && pair.getY() < boardSize);
}

bool GameBoard::shipSpace(IntPair pair, int shipSize, bool isVertical, bool &directionRightOrDown) {
    bool canPlaceShipLeftOrUp = true;
    bool canPlaceShipRightOrDown = true;
    for (int i = 0; i < shipSize; i++) {
        // if the boat is vertical
        if (isVertical) {
            // check the ship can be placed below the point
            if (onBoard(IntPair(pair.getX(), pair.getY() + i))) {
                if (board[pair.getX()][pair.getY() + i] != nullptr) {
                    canPlaceShipRightOrDown = false;
                }
            } else {
                canPlaceShipRightOrDown = false;
            }
            // check if the ship can be placed above the point
            if (onBoard(IntPair(pair.getX(), pair.getY() - i))) {
                if (board[pair.getX()][pair.getY() - i] != nullptr) {
                    canPlaceShipLeftOrUp = false;
                }
            } else {
                canPlaceShipLeftOrUp = false;
            }
        } // if the boat is horizontal
        else {
            // check if the ship can be placed to the right of the point
            if (onBoard(IntPair(pair.getX() + i, pair.getY()))) {
                if (board[pair.getX() + i][pair.getY()] != nullptr) {
                    canPlaceShipRightOrDown = false;
                }
            } else {
                canPlaceShipRightOrDown = false;
            }
            // check if the ship can be placed to the left of the point
            if (onBoard(IntPair(pair.getX() - i, pair.getY()))) {
                if (board[pair.getX() - i][pair.getY()] != nullptr) {
                    canPlaceShipLeftOrUp = false;
                }
            } else {
                canPlaceShipLeftOrUp = false;
            }
        }
    }

    // return and set value of directionLeftOrUp
    directionRightOrDown = canPlaceShipRightOrDown;
    if (canPlaceShipLeftOrUp || canPlaceShipRightOrDown) {
        return true;
    }
    return false;
}

void GameBoard::placeShip(const vector<IntPair>& locations, Ship *ship) {
    for (IntPair pair : locations) {
        setPos(pair, ship);
    }
}

void GameBoard::setPos(IntPair pair, Ship *ship) {
    board[pair.getX()][pair.getY()] = ship;
}
