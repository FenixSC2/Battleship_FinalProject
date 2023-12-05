//
// Created by natha on 11/28/2023.
//

#include "../include/IntPair.h"

IntPair::IntPair() {
    // (0, 0) is default
    x = 0;
    y = 0;
}

// constructor with non-default values
IntPair::IntPair(int a, int b) {
    x = a;
    y = b;
}

void IntPair::setX(int a) {
    x = a;
}

void IntPair::setY(int b) {
    y = b;
}

void IntPair::setPair(int a, int b) {
    x = a;
    y = b;
}

int IntPair::getX() const {
    return x;
}

int IntPair::getY() const {
    return y;
}

IntPair &IntPair::operator=(const IntPair &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool IntPair::operator==(const IntPair &other) const {
    return (x == other.x) && (y == other.y);
}

