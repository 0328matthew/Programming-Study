#include <iostream>
using namespace std;

#ifndef SORTEDARRAY_H
#define SORETEARRAY_H

class SortedArray {

    private:

        int capacity;
        int size;
        int* arr;

    public:
        
        SortedArray(int capacity);
        ~SortedArray();
        
        void insert(int value);
        void print() const;

};

#endif