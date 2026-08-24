#include <iostream>

using namespace std;

int main() {
    int meanScore = 0;
    cin >> meanScore;
    char grade;
    if(meanScore > 90) 
        grade = 'A';
    else if(meanScore > 80)
        grade = 'B';
    else if(meanScore > 70)
        grade = 'C';
    else if(meanScore > 60)
        grade = 'D';
    else
        grade = 'F';
    cout << "학점은 " << grade << "입니다." << endl;
    return 0;
}