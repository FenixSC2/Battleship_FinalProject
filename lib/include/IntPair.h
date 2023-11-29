//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_INTPAIR_H
#define BATTLESHIP_FINALPROJECT_INTPAIR_H


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
    int getX();
    int getY();
    // changes the value at memory address that was input in, works like a getter but sets the input values
    void getPair(int &a, int &b);
};


#endif //BATTLESHIP_FINALPROJECT_INTPAIR_H
