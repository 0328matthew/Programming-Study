#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

    int array[10] = {0};
    int max = 0;
    int min =100;


    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 101;
        if(array[i] > max) {
            max = array[i];
        }
        if(array[i] < min) {
            min = array[i];
        }

        cout << "이 배열의 " << i << "번째 요소는 " << array[i] << "입니다." << endl;
    }

    cout << "배열 요소 중 최대값은: " << max << "입니다." << endl;
    cout << "배열 요소 중 최소값은: " << min << "입니다." << endl;

    system("pause");
    return 0;

}