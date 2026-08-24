#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    
    while(true) {
        cin >> num1 >> num2;

        // 예외 처리 (범위를 벗어나거나 두 수가 같은 경우)
        if(num1 < 1 || num1 > 100 || num2 < 1 || num2 > 100 || num1 == num2) {
            cout << "유효하지 않은 숫자입니다. 다시 입력해 주십시오." << endl;
            continue;
        }

        int minNum = (num1 < num2) ? num1 : num2;

        for(int i = 1; i <= minNum; i++) {

            if(num1 % i == 0 && num2 % i == 0) {
                cout << i << ' ';
            }
        }
        cout << endl;
        
        break;
    }

    return 0;
}