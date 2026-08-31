#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int& getMax(int& a, int& b, int& c);

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int num1 = rand();
    int num2 = rand();
    int num3 = rand();

    cout << num1 << "  " << num2 << "  " << num3 << endl;

    int& maxNum = getMax(num1, num2, num3);

    cout << "제일 큰 정수는 " << maxNum << "입니다.";

    system("pause");
    return 0;
}

int& getMax(int& a, int& b, int& c) {
    if(a >= b && a >= c) {
        return a;
    }
    else if(b >= a && b >= c) {
        return b;
    }
    else {
        return c;
    }
}