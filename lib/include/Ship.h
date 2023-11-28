//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_SHIP_H
#define BATTLESHIP_FINALPROJECT_SHIP_H


#include <vector>
#include "IntPair.h"

class Ship {
private:
    // data about this ship
    int shipNumber;
    int shipSize;
    int numTimesHit;
    // this will be populated with the locations on the game board that the ship is in
    std::vector<IntPair> locations;
public:
    // constructors
    Ship(int number, int size);
    Ship(int number, int size, std::vector<IntPair> loc);
    // determines if the input position would hit this boat
    bool gotHit(IntPair pos);
};


#endif //BATTLESHIP_FINALPROJECT_SHIP_H
