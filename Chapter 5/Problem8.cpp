#include <iostream>
using namespace std;

int main() {
    int num;
    while(true) {
        cin >> num;
        if(num < 1 || num > 100) {
            cout << "유효하지 않은 수입니다. 다시 입력해 주세요." << endl;
            continue;
        } 
        else {
            for(int i = 1; i <= num; i++) {
                if(num % i == 0) {
                    cout << i << ' ';
                }
            }
            cout << endl;
        }
    }
    return 0;
}