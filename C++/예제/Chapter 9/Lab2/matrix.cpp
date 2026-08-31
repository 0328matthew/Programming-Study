#include "matrix.h"

Matrix::Matrix(int r, int c) : rowSize(r), colSize(c) {
    ptr = new int*[rowSize];
}