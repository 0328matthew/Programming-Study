#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print();

int main() {
    int array[100] = {0};
    srand(static_cast<unsigned>(time(nullptr)))
    for(int i = 0; i < 100; i++) {
        array[i] = 100 + rand() % 101;
    }
}

void print() {
    int num = 0;
    cout << "이 배열의 " << num << "번째 요소는 " << array[num] << "입니다."
}