#include <iostream>
using namespace std;

#ifndef MULTITABLE_H
#define MULTITABLE_H

class MultiTable {
    private:
        static const int MAX = 10;
        int** arr;
        int size1;
        int size2;
    public:
        MultiTable(int s1, int s2);
        ~MultiTable();
        void print() const;
};

#endif