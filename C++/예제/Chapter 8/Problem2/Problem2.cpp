#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int max = 1;
    int min = 1;
    int array[10] = {0};

    srand(static_cast<unsigned>(time(nullptr)));
    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 10;
    }
    for(int j = 0; j < 10; j++) {
        if(array[j] > max) {
            max = array[j + 1];
        }
        if(array[j] < min) {
            min = array[j + 1];
        }
    }
    cout << "최대값은: " << max << "입니다." << endl;
    cout << "최소값은: " << min << "입니다." << endl;

    system("pause");
    return 0;
}