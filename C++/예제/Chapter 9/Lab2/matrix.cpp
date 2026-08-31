#include "matrix.h"

Matrix::Matrix(int r, int c) : rowSize(r), colSize(c) {
    ptr = new int*[rowSize];
    for(int i = 0; i < rowSize; i++) {
        ptr[i] = new int[colSize];
    }
}

Matrix::~Matrix() {
    delete[] ptr[i];
}