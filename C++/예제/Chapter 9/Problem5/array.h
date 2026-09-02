#include <iostream>
using namespace std;

#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

// 불변식(invariant): 항상 arr[0] <= arr[1] <= ... <= arr[size-1]
class SortedArray {

    private:

        int capacity;
        int size;
        int* arr;

    public:

        SortedArray(int capacity);
        ~SortedArray();

        void insert(int value);   // 정렬 상태를 유지하며 알맞은 위치에 삽입
        void remove(int idx);     // idx번째 원소를 지우고 뒤를 당겨 구멍을 메움
        void print() const;

};

#endif
