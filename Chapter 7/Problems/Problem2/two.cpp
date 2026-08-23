#include "two.h"
#include <iostream>
using namespace std;

Two::Two(int num, char alpha)
: x(num), a(alpha) {
    getX();
    getA();
}

Two::Two()
: x(0), a('0') {
}

Two::Two(const Two& two) 
: x(two.x), a(two.a) {
}

Two::~Two() {

}

int Two::getX() const {
    return x;
}

char Two::getA() const {
    return a;
}

void Two::print() const {
    cout << "입력된 숫자는: " << x << " 입니다." << endl;
    cout << "입력된 문자열은: " << a << " 입니다." << endl;
}

void Two::setX(int num) {
    x = num;
}

void Two::setA(char alpha) {
    a = alpha;
}