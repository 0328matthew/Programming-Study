#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 6;

void diagMatrix(const int array[][SIZE], int diag[], int size);
void antiDiagMatrix(const int array[][SIZE], int antiDiag[], int size);

int main() {
    int array[SIZE][SIZE] = {0};
    int diagM[SIZE] = {0};
    int antiDiagM[SIZE] = {0};
    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            array[i][j] = 100 + rand() % 100;
        }
    }

    diagMatrix(array, diagM, SIZE);
    antiDiagMatrix(array, antiDiagM, SIZE);

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << "원래 행렬의 " << i + 1 << "행, " << j + 1 << "열의 값은: " << array[i][j] << " 입니다." << endl;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        cout << "대각 행렬의 " << i + 1 << "번째 요소의 값은: " << diagM[i] << " 입니다." << endl;
    }

    for(int i = 0; i < SIZE; i++) {
        cout << "역대각 행렬의 " << i + 1 << "번째 요소의 값은: " << antiDiagM[i] << " 입니다." << endl;
    }

    system("pause");
    return 0;
}

void diagMatrix(const int array[][SIZE], int diagM[], int size) {
    for(int i = 0; i < size; i++) {
        diagM[i] = array[i][i];
    }
}

void antiDiagMatrix(const int array[][SIZE], int antiDiagM[], int size) {
    for(int i = 0; i < size; i++) {
        antiDiagM[i] = array[i][size - 1 - i];
    }

}