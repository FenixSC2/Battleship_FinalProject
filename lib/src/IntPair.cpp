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

int IntPair::getX() {
    return x;
}

int IntPair::getY() {
    return y;
}

void IntPair::getPair(int &a, int &b) {
    a = x;
    b = y;
}
