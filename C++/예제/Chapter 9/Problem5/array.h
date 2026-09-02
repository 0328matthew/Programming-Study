#include <iostream>
using namespace std;

#ifndef SortedARRAY_H
#define ARRAY_H

class SortedArray {

    private:

        int capacity;
        int size;
        int* arr;

    public:
        
        Array(int capacity);
        ~Array();
        
        void insert(int value);
        void print() const;

};

#endif