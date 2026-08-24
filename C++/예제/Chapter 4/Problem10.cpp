#include <iostream>
#include <string>
using namespace std;

int main() {
    int day, month, year;
    int weekday;
    
    cin >> day;
    cin >> month;
    cin >> year;

    if(month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }

    weekday = (day + 26 * (month + 1) / 10 + year + year / 4 - year / 100 + year / 400) % 7;

    switch(weekday) {
        case 0 : cout << "해당일은 토요일 입니다." << endl;
                break;
        case 1 : cout << "해당일은 일요일 입니다." << endl;
                break;
        case 2 : cout << "해당일은 월요일 입니다." << endl;
                break;
        case 3 : cout << "해당일은 화요일 입니다." << endl;
                break;
        case 4 : cout << "해당일은 수요일 입니다." << endl;
                break;
        case 5 : cout << "해당일은 목요일 입니다." << endl;
                break;
        case 6 : cout << "해당일은 금요일 입니다." << endl;
                break;
    }
    return 0;
}