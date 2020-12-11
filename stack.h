#include "item_type.h"

class Stack {
    private:
        ItemType* head;
    public:
        /* Constructors and destructors */
        Stack();
        ~Stack();
        /* Stack methods */
        bool isEmpty();
        void push(ItemType* item);
        ItemType* pop();
};