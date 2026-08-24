#include <iostream>
#include <limits>

using namespace std;

int main() {
    int score1, score2, score3;
    int maxScore, minScore;
    double average;

    cout << "세 개의 점수를 입력하세요: ";
    cin >> score1 >> score2 >> score3;

    if(score1 > score2 && score1 > score3)
        maxScore = score1;
    else if(score2 > score1 && score2 > score3)
        maxScore = score2;
    else
        maxScore = score3;

    if(score1 < score2 && score1 < score3)
        minScore = score1;
    else if(score2 < score1 && score2 < score3)
        minScore = score2;
    else
        minScore = score3;

    cout << "점수는: " << static_cast<double>((maxScore + minScore) / 2) << endl;

    std::cout << "아무 키나 누르면 종료합니다..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 

    return 0;
}