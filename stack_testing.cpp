#include <iostream>
#include "stack.h"

using namespace std;

void push(Stack* stack) {
    int to_push = 0;
    cout << "Enter int to push: ";
    cin >> to_push;

    ItemType* new_item = new ItemType(to_push);
    stack->push(new_item);
}

void pop(Stack* stack) {
    if (stack->isEmpty()) {cout << "Cannot pop. stack is empty." << endl; }
    else { cout << "Poped var is: " << stack->pop()->var << endl; }
}

void isEmpty(Stack* stack) {
    if (stack->isEmpty()) { cout << "Stack is empty" << endl; }
    else { cout << "Stack is not empty" << endl; }
}

int main() {
    bool quit = false;
    int choise;
    Stack* stack = new Stack();

    while (!quit) {
        cout << "1-push, 2-pop, 3-isEmpty, 4-quit" << endl;
        cin >> choise;
        switch (choise) {
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                isEmpty(stack);
                break;
            case 4:
                quit = true;
                break;
            default:
                quit = true;
                break;
        }
    }
}