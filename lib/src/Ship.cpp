//
// Created by natha on 11/28/2023.
//

#include "../include/Ship.h"

Ship::Ship(int number, int size) {
    shipNumber = number;
    shipSize = size;
    numTimesHit = 0;
}

Ship::Ship(int number, int size, std::vector<IntPair> loc) {
    shipNumber = number;
    shipSize = size;
    numTimesHit = 0;
    locations = loc;
}

void Ship::addLocation(IntPair p) {
    locations.push_back(p);
}

bool Ship::gotHit(IntPair pos) {
    for (IntPair pair : locations) {
        if (pair == pos) {
            return true;
        }
    }
    return false;
}

bool Ship::hit(IntPair pos) {
    // check that this position is possible to hit given the current location
    if (gotHit(pos)) {
        // increase the number of times hit
        numTimesHit++;

        // remove this location from the locations that the ship is in to prevent any issues
        auto it = std::find(locations.begin(), locations.end(), pos);
        if (it != locations.end()) {
            locations.erase(it);
        }
    }
}

bool Ship::isSunk() {
    return (numTimesHit >= shipSize);
}

Ship::Ship(const Ship &other) {
    shipNumber = other.shipNumber;
    shipSize = other.shipSize;
    numTimesHit = other.numTimesHit;
    locations = other.locations;  // This performs a deep copy of the vector
}

Ship &Ship::operator=(const Ship &other) {
    if (this != &other) { // Check for self-assignment
        // Copy the content of 'other' to 'this'
        shipNumber = other.shipNumber;
        shipSize = other.shipSize;
        numTimesHit = other.numTimesHit;
        locations = other.locations;  // This performs a deep copy of the vector
    }
    return *this;
}

int Ship::display() {
    return shipNumber;
}

int Ship::getSize() {
    return shipSize;
}

Ship::~Ship() = default;
