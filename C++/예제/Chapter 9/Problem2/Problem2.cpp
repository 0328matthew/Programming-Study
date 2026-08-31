#include "fraction.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    Fraction num1 = Fraction(rand(), rand() % RAND_MAX + 1);
    Fraction num2 = Fraction(rand(), rand() % RAND_MAX + 1);
    Fraction num3 = Fraction(rand(), rand() % RAND_MAX + 1);


    cout << num1.getNumer() << " / " << num1.getDenom() << "   " << num2.getNumer() << " / " << num2.getDenom() << "   " << num3.getNumer() << " / " << num3.getDenom() << endl;

    Fraction& maxNum = larger(num1, num2, num3);

    cout << maxNum.getNumer() << " / " << maxNum.getDenom() << endl;

    system("pause");
    return 0;
}

