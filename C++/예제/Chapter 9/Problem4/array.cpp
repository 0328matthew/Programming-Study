#include "array.h"

Array::Array(int c) : capacity(c) {
    arr = new int[capacity];
}

Array::~Array() {
    delete[] arr;
}

void Array::insert(int value) {
    if(size >= capacity) {
        cout << "배열이 꽉 차서 더 이상 요소를 추가할 수 없습니다." << endl;
    }
}