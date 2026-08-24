#include <iostream>
using namespace std;

int main() {
    char carType;
    int price = 0;
    int time= 0;
    cin >> carType >> time;
    if(carType == 'c') {
        price = 2 * time;
    }
    else if(carType == 'b') {
        price = 3 * time;
    }
    else if(carType == 't') {
        price = 4 * time;
    }
    else
        cout << "지정되지 않은 종류의 차량입니다."  << endl;
    cout << "주차 요금은: " << price << "달러 입니다." << endl;
    return 0;
}