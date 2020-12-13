#include <iostream>
#include "karatsubaRec.h"
using namespace std;

int main() {

    /* longMulti test: */
    int n = 5;
    int *a = new int[n]; 
    int *b = new int[n];
    a[0] = 9;
    a[1] = 9;
    a[2] = 9;
    a[3] = 9;
    a[4] = 9;
    //a[5] = 6;
    b[0] = 9;
    b[1] = 9;
    b[2] = 9;
    b[3] = 9;
    b[4] = 9;
    //a[5] = 6;

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
