#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

double& getMax(double& a, double& b, double& c);

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    double num1 = rand();
    double num2 = rand();
    double num3 = rand();

    cout << num1 << "  " << num2 << " " << num3 << " " << endl;

    double maxNum = getMax&
}