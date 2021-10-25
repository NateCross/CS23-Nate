#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *nd;
struct node {
    int data;
    nd next;
} QUEUE;

void createQueue(nd *front, nd *rear) {
    *front = NULL;
    *rear = NULL;
}

void enQueue(nd *front, nd *rear, int input) {
    nd temp = malloc(sizeof(QUEUE));
    temp->data = input;
    temp->next = NULL;
    if (*rear == NULL) {
        *rear = temp;
        *front = *rear;
    }
    else {
        (*rear)->next = temp;
        *rear = temp;
    }

    return;
}

int deQueue(nd *front, nd *rear) {
    nd temp = *front;
    int dataToReturn = temp->data;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
    return dataToReturn;
}

bool isEmpty(nd rear) {
    if (rear == NULL)
        return true;
    else
        return false;
}

int main() {
    nd front, rear;
    createQueue(&front, &rear);
    enQueue(&front, &rear, 1);
    enQueue(&front, &rear, 2);
    enQueue(&front, &rear, 3);
    int number = deQueue(&front, &rear);
    printf("%d\n", number);
    number = deQueue(&front, &rear);
    printf("%d\n", number);
    number = deQueue(&front, &rear);
    printf("%d\n", number);
    if (isEmpty(rear))
        printf("Yeah empty\n");
}