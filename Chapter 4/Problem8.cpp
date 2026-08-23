#include <iostream>
using namespace std;

int main() {
    int x, y;

    cout << "x 좌표를 입력하세요: ";
    cin >> x;
    cout << "y 좌표를 입력하세요: ";
    cin >> y;

    if(x > 0 && y > 0)
        cout << "위 좌표는 1사분면 입니다." << endl;
    else if(x < 0 && y > 0)
        cout << "위 좌표는 2사분면 입니다." << endl;
    else if(x < 0 && y < 0)
        cout << "위 좌표는 3사분면 입니다." << endl;
    else if(x > 0 && y < 0)
        cout << "위 좌표는 4사분면 입니다." << endl;
    else
        cout << "위 좌표는 사분면에 위치하여 있지 않습니다." << endl;
    return 0;

}