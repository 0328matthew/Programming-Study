#include "array.h"

Array::Array(int c) : capacity(c) {
    arr = new int[capacity];
}

Array::~Array() {
    delete[] arr;
}

Array::insert() {
    
}