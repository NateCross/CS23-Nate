#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO: Integer to binary test

typedef struct NODE *NODE;
struct NODE { //The thingy here must be the same as the struct name, the first thingy, declared above.
    int num;
    NODE next; //Already a pointer so no need to put pointer again
} stackNode; //I guess this is a name for my reference?

void push (NODE *tos, int data) {
    NODE temp = malloc(sizeof(NODE));
    temp -> num = data;
    temp -> next = *tos;
    *tos = temp;
    return;
}

int pop (NODE *tos) {
    int data = (*tos) -> num;
    *tos = (*tos) -> next;
    return data;
}

/*
void readBinary (NODE *stack) {
    NODE temp = malloc(sizeof(NODE));
    temp = stack;
    while (temp != NULL)
        pop(temp); //TODO: Pop function
}
*/

void intToBinary (int intNum) {
    if (intNum % 2 == 0) {

    }
}

int main() {
    NODE top = malloc(sizeof(NODE)); //No need to typecast but ig we can if we need to
    top -> num = 5;
    printf("%d\n", top -> num);

    push(&top, 2);
    push(&top, 3);
    printf("%d %d\n", top -> num, top -> next -> num);
    int anotherTest = pop(&top);
    printf("%d %d %d", anotherTest, top -> num, top -> next -> num);

}
