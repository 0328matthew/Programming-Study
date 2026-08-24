#include <iostream>
using namespace std;

int main() {
    double number;
    int intNumber;
    double fracNumber;
    char dummy;

    cout << "숫자를 입력하세요: ";
    cin >> number;

    intNumber = static_cast<int>(number);
    fracNumber = number - intNumber;

    cout << "정수 부분: " << intNumber << endl;
    cout << "소수 부분: " << fracNumber << endl;

    cin >> dummy;
    return 0;
}