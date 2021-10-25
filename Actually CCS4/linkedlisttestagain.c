#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *nd;
struct node {
    int data;
    nd next;
} NODE;

nd createStack() {
    nd temp = NULL;
    return temp;
}

void push(nd *tos, int input) {
    nd temp = malloc(sizeof(NODE));
    temp->data = input;
    temp->next = *tos;
    *tos = temp;
    return;
}

int pop(nd *tos) {
    nd temp = *tos;
    int poppedData = temp->data;
    *tos = (*tos)->next;
    free (temp);
    return poppedData;
}

bool isEmpty(nd tos) {
    if (tos == NULL)
        return true;
    else
        return false;
}

int peek(nd tos) {
    return tos->data;
}

int main() {
    nd test = createStack();
    push(&test, 5);
    push(&test, 7);
    int nice = pop(&test);
    int noice = pop(&test);
    printf("%d %d\n", nice, noice);
    if (isEmpty(test))
        printf("lmao");
    return 0;
}