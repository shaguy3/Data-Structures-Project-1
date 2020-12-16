#include "longmulti.h"

int* longMulti(int* a, int* b, int n) {
    int* res = new int[2 * n];
    for (int t = 0; t < 2 * n; t++)
    {
        res[t] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            res[i + j + 1] += (a[i] * b[j]) % 10;
            res[i + j] += (a[i] * b[j]) / 10;
        }
    }

    fixDigits(res, 2 * n);

    return res;
}
