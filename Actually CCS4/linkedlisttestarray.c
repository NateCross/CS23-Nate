#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int tos;
    int stack[4];
} STACK;

STACK createStack() {
    STACK temp;
    temp.tos = -1;
    return temp;
}

void push(STACK *stk, int data) {
    stk->tos++;
    stk->stack[stk->tos] = data;
    return;
}

int pop(STACK *stk) {
    int dataToReturn = stk->stack[stk->tos];
    stk->tos--;
    return dataToReturn;
}

int peek(STACK stk) {
    return stk.stack[stk.tos];
}

bool isEmpty(STACK stk) {
    if (stk.tos == -1)
        return true;
    else
        return false;
}

bool isFull (STACK stk) {
    if (stk.tos == 3)
        return true;
    else
        return false;
}

int main() {
    int someNumber;
    STACK test = createStack();
    push(&test, 1);
    push(&test, 2);
    push(&test, 3);
    push(&test, 4);
    if (isFull(test))
        printf("Is full\n");
    for (int i = test.tos; i >= 0; i--) {
        someNumber = pop(&test);
        printf("num: %d\n", someNumber);
    }
    if (isEmpty(test))
        printf("Empty now\n");

    return 0;
}