#include <iostream>

using namespace std;

int main() {
    int num;
    int numPositive = 0;
    int numNegative = 0;

    while(true) {
        cin >> num;
        if(num == 0) {
            break;
        }
        else {
            if(num > 0) {
                numPositive++;
            }
            else {
                numNegative++;
            }
        }
    }

    cout << "입력받은 양수의 개수는  " << numPositive << "이고, 음수의 개수는: " << numNegative << "입니다." << endl;

    return 0;
}