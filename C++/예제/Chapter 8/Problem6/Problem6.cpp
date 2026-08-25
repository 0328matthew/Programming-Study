#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

    int array[10] = {0};
    int reversedArray[10] = {0};

    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 101;
        cout << array[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        reversedArray[9 - i] = array[i];
    }
    for(int i = 0; i < 10; i++) {
        cout << reversedArray[i]<< " ";
    } 

    system("pause");
    return 0;
}