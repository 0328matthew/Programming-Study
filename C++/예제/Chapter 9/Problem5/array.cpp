#include "array.h"

SortedArray::SortedArray(int c) : capacity(c), size(0) {
    arr = new int[capacity];
}

SortedArray::~SortedArray() {
    delete[] arr;
}

void SortedArray::insert(int value) {
    if(size >= capacity) {
        cout << "배열이 꽉 차서 더 이상 요소를 추가할 수 없습니다." << endl;
        return;
    }
    arr[size] = value;
    size++;
}

void SoretedArray::remove(int idx) {
    if(idx = size) {
        
    }
}

void SortedArray::print() const {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "현재 배열의 크기는: " << size << "이고, 배열의 최대 크기는: " << capacity << " 입니다." << endl;
}