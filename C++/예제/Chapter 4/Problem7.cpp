#include <iostream>

using namespace std;

int main() {
    int EA = 0;
    int priceEach = 0;
    int priceTotal = 0;
    cout << "수량을 입력하세요: "; 
    cin >> EA;
    cout << "가격을 입력하세요: " ;
    cin >> priceEach;
    if(EA <= 9)
        priceTotal = EA * priceEach;
    else if(EA <= 49)
        priceTotal = 0.97 * EA * priceEach;
    else if(EA <= 99)
        priceTotal = 0.95 * EA * priceEach;
    else if(EA >= 100)
        priceTotal = 0.9 * EA * priceEach;
    else
        cout << "유효하지 않은 수량입니다." << endl;
    cout << "총 가격은: " << priceTotal << "달러 입니다." << endl;
    return 0;
}