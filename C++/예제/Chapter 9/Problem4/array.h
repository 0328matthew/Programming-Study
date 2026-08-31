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
        
        Array(int capacity);
        ~Array();
        
        void insert(int value);
        void print() const;

};

#endif