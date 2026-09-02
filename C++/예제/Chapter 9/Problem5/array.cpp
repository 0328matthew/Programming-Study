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

    // 뒤에서부터 훑으며 value보다 큰 원소를 한 칸씩 오른쪽으로 민다.
    // 루프가 멈춘 지점 바로 뒤(i + 1)가 value가 들어갈 자리다.
    int i = size - 1;
    while(i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = value;
    size++;
}

void SortedArray::remove(int idx) {
    if(idx < 0 || idx >= size) {
        cout << "잘못된 인덱스입니다: " << idx << endl;
        return;
    }

    // 지운 자리 뒤의 원소들을 한 칸씩 왼쪽으로 당겨 구멍을 메운다.
    for(int i = idx; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void SortedArray::print() const {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "| 현재 배열의 크기는: " << size << "이고, 배열의 최대 크기는: " << capacity << " 입니다." << endl;
}
