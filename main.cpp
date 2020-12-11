#include <iostream>
#include "karatsubaRec.h"
using namespace std;

int main() {

    /* longMulti test: */
    int n = 3;
    int *a = new int[n];
    int *b = new int[n];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    b[0] = 2;
    b[1] = 2;
    b[2] = 5;
    int* res = new int[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        res[i] = 0;
    }
    karatsubaRec(a, b, n, res);
    int j = 0;
    while (res[j] == 0)
    {
        j++;
    }
    for (int i = j; i < 2 * n; i++) {
        cout << res[i];
    }

    cout << endl;

    return 0;
}
