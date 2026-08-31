#include "fraction.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    Fraction num1 = Fraction(rand(), rand() % RAND_MAX + 1);
    Fraction num2 = Fraction(rand(), rand() % RAND_MAX + 1);
    Fraction result = Fraction();

    cout << num1.getNumer() << " / " << num1.getDenom() << "   " << num2.getNumer() << " / " << num2.getDenom() << endl;

    Fraction& multiplied = multiply(num1, num2, result);

    cout << multiplied.getNumer() << " / " << multiplied.getDenom() << endl;
    system("pause");
    return 0;
}

