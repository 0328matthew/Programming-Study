#include "Point.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
using namespace std;

int main() {

    // 변수 설정
    int x1, y1;
    int x2, y2;

    // 변수 입력
    cout << "첫번째 점의 x, y 좌표를 입력하세요: ";
    cin >> x1;
    cin >> y1;
    cout << endl << "두번째 점의 x, y 좌표를 입력하세요: ";
    cin >> x2;
    cin >> y2;
    cout << endl;

    // 유효성 확인
    if(!cin) {
        assert(false);
    }

    // 1번 객체 설정
    Point point1(0, 0);
    point1.setX(x1);
    point1.setY(y1);
    point1.print();

    // 2번 객체 지정
    Point point2(point1);
    point2.setX(x2);
    point2.setY(y2);
    point2.print();

    // 방향, 거리 도출
    point1.direction(point2);
    point1.distance(point2);

    system("pause");
    return 0;
}