#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int array[20] = {0};
    int oddArray[20] = {0};
    int evenArray[20] = {0};
    int j = 0;
    int k = 0;

    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < 20; i++) {
        array[i] = rand() %101;
    }
    for(int i = 0; i < 20; i++) {
        if(array[i] % 2 == 0) {
            evenArray[j] = array[i];
            j++;
        }
        else {
            oddArray[k] = array[i];
            k++;
        }
    }

    for(int i = 0; i < 20; i++) {
        cout << "원래 배열의 " << i << "번째 요소는 " << array[i] << " 입니다." << endl;
    }
    cout << endl;
    for(int i = 0; i < j; i++) {
        cout << "짝수 배열의 " << i << "번째 요소는 " << evenArray[i] << " 입니다." << endl;
    }
    cout << endl;
    for(int i = 0; i < k; i++) {
        cout << "홀수 배열의 " << i << "번째 요소는 " << oddArray[i] << " 입니다." << endl;
    }

    system("pause");
    return 0;

}