#include <iostream>
using namespace std;

#ifndef ONE_H
#define ONE_H

class One {

    private:

    int X;
    int Y;

    public:

    One(int x, int y);
    One();
    One(const One& one);
    ~One();

    int getX() const;
    int getY() const;
    void print() const;

    void setX(int x);
    void setY(int y);
};

#endif