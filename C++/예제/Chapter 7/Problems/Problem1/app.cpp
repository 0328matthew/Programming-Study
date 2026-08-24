#include "one.h"
#include <iostream>
#include <cstdlib>

int main() {
    int n1, n2;

    cin >> n1;
    cin >> n2;

    One one1;
    one1.setX(n1);
    one1.setY(n2);
    one1.print();

    system("pause");
    return 0;
}