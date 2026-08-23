#include <iostream>
#include <limits>
using namespace std;

int main() {
    int number;
    int firstDigit;



    cout << "숫자를 입력하세요: ";
    cin >> number;

    firstDigit = number%10;

    cout << "입력한 숫자의 첫 번째 자리: " << firstDigit << endl;

    std::cout << "아무 키나 누르면 종료합니다..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 

    return 0;
}