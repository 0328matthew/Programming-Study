#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

void print(const int array[], int i);

void roundShift(int array[], int i);


int main() {

    int array[10] = {0};
    int arrayShifted[10] = {0};

    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 10;
    }
    print(array, 10);
    cout << endl;
    roundShift(array, 10);
    print(array, 10);

    system("pause");
    return 0;

}

void print(const int array[], int i) {
    for(int j = 0; j < i; j++)
        cout << "이 배열의 " << j << "번째 요소는 " << array[j] << "입니다." << endl;
}


void roundShift(int array[], int i) {
    int temp = array[i - 1];
    for(int j = i - 1; j > 0; j--) {
        array[j] = array[j - 1];
    }
    array[0] = temp;
}