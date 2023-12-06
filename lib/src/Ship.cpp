//
// Created by natha on 11/28/2023.
//

#include <utility>
#include <iostream>

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
    locations = std::move(loc);
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

void Ship::hit() {
    numTimesHit++;
}

bool Ship::isSunk() const {

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

int Ship::display() const {
    return shipNumber;
}

int Ship::getSize() const {
    return shipSize;
}

Ship::~Ship() = default;
