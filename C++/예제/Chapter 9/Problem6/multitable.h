#include <iostream>
using namespace std;

#ifndef MULTITABLE_H
#define MULTITABLE_H

class MultiTable {

    private:
        int* arr;
        int size;
        int capacity;

    public:
        MultiTable(int capacity);
        ~MultiTable();

        void print() const;

};

#endif