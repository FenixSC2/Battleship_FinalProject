//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_SHIP_H
#define BATTLESHIP_FINALPROJECT_SHIP_H


#include <vector>
#include <algorithm>
#include "IntPair.h"

class Ship {
private:
    // data about this ship
    int shipNumber;
    int shipSize;
    int numTimesHit;
    // this will be populated with the locations on the game board that the ship is in
    std::vector<IntPair> locations;

    // determines if the input position would hit this boat
    bool gotHit(IntPair pos);
public:
    // constructors
    Ship(int number, int size);
    Ship(int number, int size, std::vector<IntPair> loc);

    // follow the rule of 3
    // Copy constructor
    Ship(const Ship& other);
    // Copy assignment operator
    Ship& operator=(const Ship& other);
    // Destructor
    ~Ship();

    // adds a location to the locations field
    void addLocation(IntPair p);

    /*
     * Hit is the main thing that will be called each turn of the game.
     * - returns true if this ship is hit by the location input
     *      - adds 1 to the count of hits on this ship
     *      - Also removes the hit location from the list of locations to prevent it getting hit again
     * - otherwise returns false
     */
    bool hit(IntPair pos);
    // determines if this ship is sunk
    bool isSunk();

    // displays the number of this ship for the ASCII visualization
    int display();
    // returns the size of this ship
    int getSize();
};


#endif //BATTLESHIP_FINALPROJECT_SHIP_H
