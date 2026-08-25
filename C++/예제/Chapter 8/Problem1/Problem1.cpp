#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(const int array[], int i);

int main() {
    int array[100] = {0};
    srand(static_cast<unsigned>(time(nullptr)));
    for(int i = 0; i < 100; i++) {
        array[i] = 100 + rand() % 101;
        print(array, i);
    }
    

    system("pause");
    return 0;
}

void print(const int array[], int i) {
    cout << "이 배열의 " << i << "번째 요소는 " << array[i] << " 입니다." << endl;
}