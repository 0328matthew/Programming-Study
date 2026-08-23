#include <iostream>

using namespace std;

int main() {
    int lineNum, type;

    cin >> lineNum;
    cin >> type;

    switch(type) {
        case 1:
            for(int i = 0; i < lineNum; i++) {
                for(int j = 0; j < i; j++) {
                    cout << ' ';
                }
                for(int k = 0; k < 2 * (lineNum - i) - 1; k++) {
                    cout << '*';
                }
                cout << endl;
            }
            break;

        case 2:
            for(int i = 0; i < lineNum; i++) {
                for(int j = 0; j < lineNum - 1 - i; j++) {
                    cout << ' ';
                }
                for(int k = 0; k < 2 * i + 1; k++) {
                    cout << '*';
                }
                cout << endl;
            }
            break;
    }
    return 0;
}