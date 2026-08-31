#include <iostream>
#include <cmath>
#include <cassert>
#include "fraction.h"
using namespace std;

Fraction::Fraction(int num, int den = 1)
: numer(num), denom(den) {
    normalize();
}

Fraction::Fraction()
: numer(0), denom(1) {

}

Fraction::Fraction(const Fraction& fract)
: numer(fract.numer), denom(fract.denom) {

}

Fraction::~Fraction() {

}


int Fraction::getNumer() const {
    return numer;
}

int Fraction::getDenom() const {
    return denom;
}


void Fraction::print() const {
    cout << numer << "/" << denom << endl;
}

void Fraction::setNumer(int num) {
    numer = num;
    normalize();
}

void Fraction::setDenom(int den) {
    denom = den;
    normalize();
}

void Fraction::normalize() {
    if(denom == 0) {
        cout << "잘못된 분모 값입니다. 프로그램을 중단합니다." << endl;
        assert(false);
    }

    if(denom < 0) {
        denom = -denom;
        numer = -numer;
    }

    int divisor = gcd(abs(numer), abs(denom));
    numer = numer / divisor;
    denom = denom / divisor;
}

int Fraction::gcd(int n, int m) {
    int gcd = 1;
    for(int k = 1; k <= n && k <= m; k++) {
        if(n % k == 0 && m % k == 0) {
            gcd = k;
        }
    }
    return gcd;
}

Fraction& larger(Fraction& fract1, Fraction& fract2, Fraction& fract3) {
    if(fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom() && fract1.getNumer() * fract3.getDenom() > fract3.getNumer() * fract1.getDenom()) {
            return fract1;
        }
    else if(fract2.getNumer() * fract1.getDenom() > fract1.getNumer() * fract2.getDenom() && fract2.getNumer() * fract3.getDenom() > fract3.getNumer() * fract2.getDenom()) {
            return fract2;
    }
    else {
            return fract3;
    }
}

Fraction& multiply(Fraction& fract1, Fraction& fract2, Fraction& result) {
    int numer1 = fract1.getNumer();
    int denom1 = fract1.getDenom();
    int numer2 = fract2.getNumer();
    int denom2 = fract2.getDenom();
    int numResult = 0;
    int denResult = 0;

    numResult = numer1 * numer2;
    denResult = denom1 * denom2;

    result.setNumer(numResult);
    result.setDenom(denResult);

    return result;    
}