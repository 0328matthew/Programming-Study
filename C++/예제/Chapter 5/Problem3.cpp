#include <iostream>

using namespace std;

int main() {
    int num;
    int sum = 0;
    int mean = 0;
    int numCount = 0;

    while(true) {
        cin >> num;
        if(num > 1000) {
            break;
        }
        else {
            sum += num;
            numCount++;
        }
    }
    mean = sum / numCount;

    cout << "합은: " << sum << "이고, 평균은: " << mean << "입니다." << endl;

    return 0;
}