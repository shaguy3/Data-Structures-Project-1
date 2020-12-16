#include <iostream>
#include "longmulti.h"
#include "karatsubaRec.h"
#include "karatsubaIter.h"
#include "stack.h"
#include <chrono>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

bool check_input(string& a, string& b, string& n) {

    while (n[0] == ' ') {
        n.erase(0, 1);
    }

    if (n[0] == '0') {
        return false;
    }

    for (int i = 0; i < n.length(); i++) {
        if (!isdigit(n[i])) {
            return false;
        }
    }

    int num_n = atoi(n.c_str());

    while (a[0] == ' ') {
        a.erase(0, 1);
    }

    while (b[0] == ' ') {
        b.erase(0, 1);
    }

    if (a.length() != num_n || b.length() != num_n) {
        return false;
    }

    for (int i = 0; i < a.length(); i++) {
        if (!isdigit(a[i]) || (!isdigit(b[i]))) {
            return false;
        }
    }

    return true;
}

int main() {

    string str_n;
    getline(cin, str_n);
    string str_a;
    getline(cin, str_a);
    string str_b;
    getline(cin, str_b);

    if (check_input(str_a, str_b, str_n) && str_n.length() != 0) {

        int n = atoi(str_n.c_str());
        int* a = new int[n];
        int* b = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = (int)(str_a[i] - '0');
            b[i] = (int)(str_b[i] - '0');
        }

        int* res_1 = new int[2 * n];
        int* res_2 = new int[2 * n];

        for (int i = 0; i < 2 * n; i++)
        {
            res_1[i] = 0;
            res_2[i] = 0;
        }

        auto start = chrono::high_resolution_clock::now();
        // unsync the I/O of C and C++.
        ios_base::sync_with_stdio(false);
        int* long_res = longMulti(a, b, n);// Here you put the name of the function you wish to measure
        auto end = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        ofstream myfile("Measure.txt"); // The name of the file
        myfile << "Time taken by function longMulti is : " << fixed
            << time_taken << setprecision(9);
        myfile << " sec" << endl;

        start = chrono::high_resolution_clock::now();
        // unsync the I/O of C and C++.
        ios_base::sync_with_stdio(false);
        karatsubaRec(a, b, n, &res_1);// Here you put the name of the function you wish to measure
        end = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        myfile << "Time taken by function karatsubaRec is : " << fixed
            << time_taken << setprecision(9);
        myfile << " sec" << endl;

        start = chrono::high_resolution_clock::now();
        // unsync the I/O of C and C++.
        ios_base::sync_with_stdio(false);
        karatsubaIter(a, b, n, res_2);// Here you put the name of the function you wish to measure
        end = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        myfile << "Time taken by function karatsubaIter is : " << fixed
            << time_taken << setprecision(9);
        myfile << " sec" << endl;
        myfile.close();

        int j = 0;
        while (long_res[j] == 0 && j <  2 * n) {
            j++;
        }
        for (int i = j; i < 2 * n; i++) {
            cout << long_res[i];
        }

        if (j == 2 * n) { cout << "0"; }

        cout << endl;

        if (n % 2 != 0)
        {
            n++;
        }

        j = 0;
        while (res_1[j] == 0 && j < 2 * n)
        {
            j++;
        }
        for (int i = j; i < 2 * n; i++) {
            cout << res_1[i];
        }

        if (j == 2 * n) { cout << "0"; }

        cout << endl;

        j = 0;
        while (res_2[j] == 0 && j < 2 * n)
        {
            j++;
        }
        for (int i = j; i < 2 * n; i++) {
            cout << res_2[i];
        }

        if (j == 2 * n) { cout << "0"; }

        cout << endl;

        delete[] a;
        delete[] b;
        delete[] res_1;
        delete[] res_2;
        delete[] long_res;

    }
    else {
        cout << "wrong output" << endl;
    }

    return 0;
}
