#include <iostream>
#include <limits>

using namespace std;

int main() {
    int num1, num2, num3;
    double average, dev1, dev2, dev3;

    cout << "숫자를 입력하세요: ";
    cin >> num1 >> num2 >> num3;

    average = static_cast<double>(num1 + num2 + num3) / 3;

    dev1 = num1 - average;
    dev2 = num2 - average;
    dev3 = num3 - average;

    cout<< "평균: " << average << endl;
    cout << "편차: " << dev1 << ", " << dev2 << ", " << dev3 << endl;

    std::cout << "아무 키나 누르면 종료합니다..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 

    return 0;

}