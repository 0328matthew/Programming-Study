#include <iostream>
using namespace std;

#ifndef MULTITABLE_H
#define MULTITABLE_H

class MultiTable {

    private:
        static const int MAX = 10;
        int arr[MAX][MAX];
        int size1, size2;

    public:
        MultiTable(int size1, int size2);
        ~MultiTable();

        void print() const;

};

#endif