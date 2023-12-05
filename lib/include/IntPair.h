//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_INTPAIR_H
#define BATTLESHIP_FINALPROJECT_INTPAIR_H

#include "random"

class IntPair {
private:
    // pair data
    int x;
    int y;
public:
    // constructor
    IntPair();
    IntPair(int a, int b);
    // overload operators
    IntPair& operator=(const IntPair &other);
    bool operator==(const IntPair &other) const;

    // setters
    void setX(int a);
    void setY(int b);
    void setPair(int a, int b);
    // getters
    int getX() const;
    int getY() const;
};


#endif //BATTLESHIP_FINALPROJECT_INTPAIR_H
