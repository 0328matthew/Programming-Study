#include "multitable.h"
using namespace std;

MultiTable::MultiTable(int c) : capacity(c), size(0) {
    arr = new int[capacity];

}

MultiTable::~MultiTable() {

}

void MultiTable::print() const {

}