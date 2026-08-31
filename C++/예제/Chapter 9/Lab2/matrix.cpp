#include "matrix.h"

Matrix::Matrix(int r, int c) : rowSize(r), colSize(c) {
    ptr = new int*[rowSize];
    for(int i = 0; i < rowSize; i++) {
        ptr[i] = new int[colSize];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < rowSize; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void Matrix::setup() {
    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < colSize; j++) {
            ptr[i][j] = rand() % 5 + 1;
        }
    }
}

void Matrix::add(const Matrix& second, Matrix& result) const {
    
}