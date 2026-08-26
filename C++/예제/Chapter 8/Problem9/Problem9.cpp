#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 5;

int main() {

    int array1[SIZE] = {0};
    int array2[SIZE] = {0};

    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < SIZE; i++) {
        array1[SIZE] = 100 + rand() % 100;
        array2[SIZE] = 100 + rnad() % 100;
    }

}