#include "two.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

int main() {

    int num1;
    char alpha1;

    Two two1(2, 'a');
    two1.print();
    cout << "재지정할 숫자를 입력 해 주세요:";
    cin >> num1;
    if(!cin) {
        cout << "유효한 입력이 아닙니다." << endl;
        assert(false);
    }
    cout << "재지정할 문자를 입력 해 주세요: ";
    cin >> alpha1;

    two1.setX(num1);
    two1.setA(alpha1);

    two1.getX();
    two1.getA();

    two1.print();


    system("pause");
    return 0;
}