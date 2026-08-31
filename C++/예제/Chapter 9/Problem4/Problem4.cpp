#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;

int main() {
    Array array1(4);

    array1.insert(10);
    array1.insert(20);
    array1.insert(30);

    array1.print();

    system("pause");
    return 0;
}