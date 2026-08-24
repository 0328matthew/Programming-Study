#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor & Destructor
Point::Point(int coordX, int coordY)
    : x(coordX), y(coordY) {

}

Point::Point() : x(0), y(0) {}

Point::Point(const Point& point)
    : x(point.x), y(point.y) {

}

Point::~Point() {}

// getter & setter
int Point::getX() const {
        return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int coordX) {
    x = coordX;
}

void Point::setY(int coordY) {
    y = coordY;
}

// 출력문
void Point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

// direction & distance
void Point::direction(const Point& point) const {
    int dx = this->x - point.x;
    int dy = this->y - point.y;
    cout << "두번째 좌표와 첫번째 좌표를 비교했을 때, 두번째 좌표는 ";
    if(dx == 0 && dy == 0) {
        cout << "같은 곳에 있습니다." << endl;
    }

    if(dx > 0) {
        cout << "왼쪽 ";
    }
    else {
        cout << "오른쪽 ";
    }

    if(dy > 0) {
        cout << "아래";
    }
    else {
        cout << "위";
    }
    cout << "에 있습니다." << endl;
}

double Point::distance(const Point& point) const {
    int dx = this->x - point.x;
    int dy = this->y - point.y;
    double distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
    cout << "두 점 사이의 거리는" << distance << "입니다." << endl;

    return distance;
}