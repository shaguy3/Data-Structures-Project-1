#include "stack.h"


Stack::Stack() :
    head(nullptr) {}

bool Stack::isEmpty() {
    if (head) { return false; }
    else { return true; }
}

void Stack::push(ItemType* _item) {
    ItemType* new_head = new ItemType(_item->x, _item->y, _item->res, _item->n, _item->line, _item->p1,
                                      _item->p1_n, _item->p2, _item->p2_n, _item->p3, _item->p3_n, _item->count);
    new_head->next = head;
    head = new_head;
}

ItemType* Stack::pop() {
    if (!head) { return nullptr; }
    else {
        ItemType* to_pop = head;
        head = head->next;
        return to_pop;
    }
}

Stack::~Stack() {
    while (head) {
        Stack::pop();
    }
}
