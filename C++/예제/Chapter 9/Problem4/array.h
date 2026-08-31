#include <iostream>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

class Array {

    private:

        int capacity;
        int size;
        int* arr;

    public:
        
        Array(int capacity, int size);
        ~Array();
        
        void Array::insert();
        void Array::print();

};

#endif