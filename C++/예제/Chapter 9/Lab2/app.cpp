#include "matrix.h"

int main() {

    cout << "matrix1" << endl;
    Matrix matrix1(3, 4);
    matrix1.setup();
    matrix1.print();

    cout << "matrix2" << endl;
    Matrix matrix2(3, 4);
    matrix2.setup();
    matrix2.print();

    cout << "matrix3" << endl;
    Matrix matrix3(4,2 );
    matrix3.setup();
    matrix3.print();

    cout << "matrix1 + matrix 2ÀÇ °á°ú" << endl;
    Matrix addResult(3, 4);
    matrix1.add(matrix2, addResult);
    addResult.print();

    

}