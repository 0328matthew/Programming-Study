#include <iostream>
#include <limits>

using namespace std;

int main() {
    int givenNumber;
    int second;
    int minute;
    int hour;


    cout << "초를 입력하세요: ";
    cin >> givenNumber;

    hour = givenNumber / 3600;
    minute = (givenNumber / 60) % 60;
    second = givenNumber % 60;
    
    cout << hour << "시간";
    cout << minute << "분";
    cout << second << "초" << endl;

    std::cout << "아무 키나 누르면 종료합니다..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 

    return 0;
}