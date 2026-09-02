#include <iostream>
using namespace std;

#ifndef SORTEDARRAY_H
#define SORETEARRAY_H

class SortedArray {

    private:

        int capacity;
        int size;
        int* arr;
        int idx;

    public:
        
        SortedArray(int capacity);
        ~SortedArray();
        
        void insert(int value);
        void remove(int idx);
        void print() const;

};

#endif