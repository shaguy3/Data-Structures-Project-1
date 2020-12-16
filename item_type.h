#pragma once

class ItemType {
public:
    int* x, * y, * res, * p1, * p2, * p3;
    int n, p1_n, p2_n, p3_n, count, line;
    ItemType* next;

    ItemType(int* _x, int* _y, int* _res, int _n, int _line, \
        int* _p1, int _p1_n, int* _p2, int _p2_n, int* p3, int p3_n, int count);
    ~ItemType();
};
