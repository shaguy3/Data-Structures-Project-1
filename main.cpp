#include <iostream>
#include "longmulti.h"
using namespace std;

int main() {

    /* longMulti test: */
    
     int n = 4;
     int a[4] = {9, 9, 9, 9};
     int b[4] = {0, 0, 5, 3};

     int* res = longMulti(a, b, n);
     int j = 0;
     while (res[j]==0)
     {
         j++;
     }
     for (int i = j; i < 2 * n; i++) {
         cout << res[i];
     }

     cout << endl;

    return 0;
}