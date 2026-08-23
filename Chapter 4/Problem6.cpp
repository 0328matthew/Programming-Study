#include <iostream>

using namespace std;

int main() {
    int price = 10;
    int credit = 0;

    cin >> credit;
    if(credit < 12) {
        price = price + credit * 10;
    }
    cout << "수업료는: " << price << "입니다." << endl;

    return 0;
}