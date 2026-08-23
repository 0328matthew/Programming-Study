#include <iostream>
using namespace std;

int main() {
    int totalBills;
    cin >> totalBills;

    int bill100 = totalBills / 100;
    totalBills = totalBills % 100;
    if(totalBills > 100)
        cout << "100달러 지폐 수는 " << bill100 << "장 입니다." << endl;
    
    int bill50 = totalBills / 50;
    totalBills = totalBills % 50;
    if(totalBills > 50)
        cout << "50달러 지폐 수는 " << bill50 << "장 입니다." << endl;
    
    int bill20 = totalBills / 20;
    totalBills = totalBills % 20;
    if(totalBills > 20)
        cout << "20달러 지폐 수는 " << bill20 << "장 입니다." << endl;
    
    int bill10 = totalBills / 10;
    totalBills = totalBills % 10;
    if(totalBills > 10)
        cout << "10달러 지폐 수는 " << bill10 << "장 입니다." << endl;
    
    int bill5 = totalBills / 5;
    totalBills = totalBills % 5;
    if(totalBills > 5)
        cout << "5달러 지폐 수는 " << bill100 << "장 입니다." << endl;

    int bill1 = totalBills / 1;
    totalBills = totalBills % 1;
    if(totalBills > 1)
        cout << "1달러 지폐 수는 " << bill1 << "장 입니다." << endl;
    
    return 0;
}