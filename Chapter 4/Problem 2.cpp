#include <iostream>
#include <limits>

using namespace std;

int main() {

    double income, tax;
    bool bracket1, bracket2, bracket3, bracket4;
    double limit1 = 10000, limit2 = 50000, limit3 = 100000;
    double rate1 = 0.05, rate2 = 0.10, rate3 = 0.15, rate4 = 0.20;

    cout << "소득을 입력하세요: ";
    cin >> income;

    bracket1 = (income <= limit1) && (income >= 0);
    bracket2 = (income > limit1) && (income <= limit2);
    bracket3 = (income > limit2) && (income <= limit3);
    bracket4 = (income > limit3);

    if(bracket1) {
        tax = income * rate1;
    } else if(bracket2) {
        tax = limit1 * rate1 + (income - limit1) * rate2;
    } else if(bracket3) {
        tax = limit1 * rate1 + (limit2 - limit1) * rate2 + (income - limit2) * rate3;
    } else if(bracket4) {
        tax = limit1 * rate1 + (limit2 - limit1) * rate2 + (limit3 - limit2) * rate3 + (income - limit3) * rate4;
    }
    else {
        cout << "잘못된 소득 입력입니다: " << endl;
        return 0;
    }

    cout << "소득: " << income << endl;
    cout << "적용할 세금: " << tax << endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 

    return 0;
}