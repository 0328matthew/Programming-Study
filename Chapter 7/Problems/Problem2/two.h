#include <iostream>
using namespace std;

#ifndef TWO_H
#define TWO_H

class Two {

    private:

        int x;
        char a;

    public:

        Two(int num, char alpha);
        Two();
        Two(const Two& two);
        ~Two();

        int getX() const;
        char getA() const;
        void print() const;

        void setX(int num);
        void setA(char alpha);

};

#endif