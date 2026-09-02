#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;

int main() {
    SortedArray array1(6);

    // 일부러 뒤죽박죽 넣어도 항상 정렬된 상태가 유지된다
    array1.insert(30);   array1.print();
    array1.insert(10);   array1.print();
    array1.insert(20);   array1.print();
    array1.insert(50);   array1.print();
    array1.insert(40);   array1.print();

    cout << "--- 인덱스 2 (값 30) 제거 ---" << endl;
    array1.remove(2);
    array1.print();

    cout << "--- 범위 밖 인덱스 시도 ---" << endl;
    array1.remove(9);
    array1.print();

    system("pause");
    return 0;
}
