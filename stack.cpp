#include <iostream>
#include "stack.h"

Stack::Stack() :
 head(nullptr) {}

bool Stack::isEmpty() {
    if (head) { return false; }
    else { return true; }
}

void Stack::push(ItemType* item) {
    ItemType* new_head = new ItemType(item->var);
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
    while(head) {
        Stack::pop();
    }
}