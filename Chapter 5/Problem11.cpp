#include <iostream>

using namespace std;

int main() {
    int num;
    int numCount = 0;
    int numMax = 0;
    int numMin = 100;


    while(true) {
        cin >> num;
        if(numCount > 10) {
            break;
        }
        if(num < 1 || num > 100) {
            cout << "유효하지 않은 숫자입니다. 다시 입력하십시오." << endl;
            continue;
        }
        else {
            if(num >= numMax) {
                numMax = num;
            }
            if( num <= numMin) {
                numMin = num;
            }
        }
        numCount++;
    }
    cout << "최대값은 " << numMax << "이고, 최소값은 " << numMin << "입니다." << endl;

    return 0;
}