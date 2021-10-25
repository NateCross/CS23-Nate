#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_MAX 5

typedef struct {
    int front;
    int rear;
    int data[QUEUE_MAX];
} QUEUE;

QUEUE createQueue() {
    QUEUE temp;
    // for (int i = 0; i < QUEUE_MAX; i++)
    //     temp.data[i] = NULL;
    temp.front = 0;
    temp.rear = -1;
    return temp;
}

void enQueue(QUEUE *q, int input) {
    q->rear++;
    q->data[q->rear] = input;
    return;
}

int deQueue(QUEUE *q) {
    int dataToReturn = q->data[q->front];
    q->front++;
    return dataToReturn;
}

bool isEmpty(QUEUE q) {
    if (q.rear == -1)
        return true;
    else
        return false;
}

bool isFull(QUEUE q) {
    if (q.rear == q.front)
        return true;
    else
        return false;
}

int main() {
    int number;
    QUEUE test = createQueue();
    enQueue(&test, 1);
    enQueue(&test, 2);
    enQueue(&test, 3);
    enQueue(&test, 4);
    enQueue(&test, 5);
    // printf("%d\n", number);
    if (isFull(test))
        printf("Is full\n");
    
    for (int i = test.front; i <= test.rear; i = i + 1) {
        number = deQueue(&test);
        printf("%d\n", number);
    }
    printf("front: %d rear: %d\n", test.front, test.rear);
    if (isEmpty(test))
        printf("Is empty\n");

    return 0;
}