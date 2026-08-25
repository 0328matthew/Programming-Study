#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int array[20] = {0};
    int oddArray[20] = {0};
    int evenArray[20] = {0};
    int j = 0;

    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < 20; i++) {
        array[i] = rand() %101;
    }
    for(int i = 0; i < 20; i++) {
        if(array[i] % 2 == 0) {
            array[i] = evenArray[j];
        }
    }

}