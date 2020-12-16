#include "item_type.h"

ItemType::ItemType(int* _x, int* _y, int* _res, int _n, int _line, \
    int* _p1, int _p1_n, int* _p2, int _p2_n, int* _p3, int _p3_n, int _count) :
    x(new int[_n]), y(new int[_n]), res(new int[2*_n]), n(_n), count(_count),
    p1(nullptr), p1_n(_p1_n), p2(nullptr), p2_n(_p2_n), p3(nullptr), p3_n(_p3_n),
    line(_line), next(nullptr) {

    for (int i = 0; i < n; i++) {
        x[i] = _x[i];
        y[i] = _y[i];
        res[i] = _res[i];
    }

    for (int i = n; i < 2 * n; i++) {
        res[i] = _res[i];
    }

    if (p1_n > 0) {
        p1 = new int[p1_n];
        for (int i = 0; i < p1_n; i++) {
            p1[i] = _p1[i];
        }
    }

    if (p2_n > 0) {
        p2 = new int[p2_n];
        for (int i = 0; i < p2_n; i++) {
            p2[i] = _p2[i];
        }
    }

    if (p3_n > 0) {
        p3 = new int[p3_n];
        for (int i = 0; i < p3_n; i++) {
            p3[i] = _p3[i];
        }
    }
}

ItemType::~ItemType() {
    /*
    TODO: deletes not working
    */
}
