#include "one.h"
#include <iostream>
using namespace std;

One::One(int x, int y)
: X(x), Y(y) {
    getX();
    getY();
}
One::One()
: X(0), Y(0) {

}
One::One(const One& one)
: X(one.X), Y(one.Y) {

}
One::~One() {

}

void One::setX(int x) {
    X = x;
}

void One::setY(int y) {
    Y = y;
}

void One::print() const {
    cout << X << endl;
    cout << Y << endl;
}

int One::getX() const {
    return X;
}

int One::getY() const {
    return Y;
} 

