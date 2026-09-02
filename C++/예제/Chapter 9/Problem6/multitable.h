#include <iostream>
#ifndef MULTITABLE_H
#define MULTITABLE_H

class MultiTable {

    private:
        int* arr;
        int size;
        int capacity;

    public:
        multiTable(int capacity);
        ~multiTable();

        void print();

};





#endif