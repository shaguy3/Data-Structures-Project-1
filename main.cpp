#include <iostream>
#include "karatsubaRec.h"
using namespace std;

int main() {

    /* longMulti test: */
    int n = 9;
    int *a = new int[n]; 
    int *b = new int[n];
   //      0 

    a[0] = 3;
    a[1] = 2;
    a[2] = 3;
    a[3] = 2;
    a[4] = 3;
    a[5] = 2;
    a[6] = 3;
    a[7] = 2;
    a[8] = 3;

    b[0] = 2;
    b[1] = 3;
    b[2] = 2;
    b[3] = 3;
    b[4] = 2;
    b[5] = 3;
    b[6] = 2;
    b[7] = 3;
    b[8] = 2;

    int* res = new int[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        res[i] = 0;
    }
    karatsubaRec(a, b, n, &res);
    if (n%2!=0)
    {
        n++;
    }
    int j = 0;
    while (res[j] == 0 && j<n)
    {
        j++;
    }
    for (int i = j; i < 2*n; i++) {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}
