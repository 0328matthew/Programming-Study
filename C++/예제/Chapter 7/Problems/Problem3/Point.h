#include <iostream>

#ifndef POINT_H
#define POINT_H

class Point {

    private:
        //x, y 좌표
        int x, y;


    public:
        //생성자 & 소멸자
        Point(int coordx, int coordy);
        Point();
        Point(const Point& point);
        ~Point();

        //getter & setter
        int getX() const;
        int getY() const;
        void setX(int coordX);
        void setY(int coordY);

        // 방향 & 거리
        void direction(const Point& point) const;
        double distance(const Point& point) const;

        // 출력문
        void print() const;

};

#endif