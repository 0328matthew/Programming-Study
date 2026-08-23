#include <iostream>

using namespace std;

int main() {
    int type;
    int size;
    cin >> type;
    cin >> size;

    switch(type) {
        case 1 : 
                for(int i = 1; i <= size; i++) {
                    for(int j = 0; j < i; j++) {
                        cout << '*';
                    }
                    cout << endl;
                }
                break;
        case 2 :
                for(int i = size; i > 0; i--) {
                    for(int j = i; j > 0; j--) {
                        cout << '*';
                    }
                    cout << endl;
                }
                break;
        case 3 :
                for(int i = 0; i < size; i++) {
                    for(int k = 0; k < i; k++) {
                        cout << ' ';
                    }
                    for(int j = 0; j < size - i; j++) {
                        cout << '*';
                    }
                    cout << endl;
                }
                break;
        case 4 :
                for(int i = 1; i <= size; i++) {
                    for(int k = 0; k < size - i; k++) {
                        cout << ' ';
                    }
                    for(int j = 0; j < i; j++) {
                        cout << '*';
                    }
                    cout << endl;
                }
                break;
    }
    return 0;
}