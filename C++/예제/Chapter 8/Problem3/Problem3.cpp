#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int main() {

    float avg = 0;
    float stddev = 0;
    float sum = 0;
    float powersum = 0;

    srand(static_cast<unsigned>(time(nullptr)));
    float array[10] = {0};

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 10;
        sum = sum + array[i];
    }

    avg = sum / 10.0;

    for(int j = 0; j < 10; j++) {
        powersum = powersum + pow(array[j] - avg, 2);
    }
    stddev = sqrt(powersum) / 2;

    cout << "평균은" << avg << "입니다." << endl;
    cout << "표준편차는" << stddev << "입니다." << endl;

    system("pause");
    return 0;


}