#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(const int array[], int idx);

int main() {
    int array[100] = {0};
    srand(static_cast<unsigned>(time(nullptr)));
    for(int i = 0; i < 100; i++) {
        array[i] = 100 + rand() % 101;
    }
    print(array, 0);
}

void print(const int array[], int idx) {
    cout << "이 배열의 " << idx << "번째 요소는 " << array[idx] << " 입니다." << endl;
}