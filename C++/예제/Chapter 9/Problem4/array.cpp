#include "array.h"

Array::Array(int c) : capacity(c) {
    arr = new int[capacity];
}