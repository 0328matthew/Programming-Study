#include "multitable.h"
using namespace std;

MultiTable::MultiTable(int s1, int s2) {
    if (s1 < 1 || s1 > MAX) s1 = MAX;
    if (s2 < 1 || s2 > MAX) s2 = MAX;
    size1 = s1;
    size2 = s2;

    arr = new int*[size1];
    for (int i = 0; i < size1; i++) {
        arr[i] = new int[size2];
    }

    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            arr[i][j] = (i + 1) * (j + 1);
}