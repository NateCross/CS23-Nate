#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_SIZE 5

typedef struct {
    int queue[QUEUE_SIZE];
    int front;
    int rear;
} QUEUE;

QUEUE createQueue() {
    QUEUE temp;
    temp.front = 0;
    temp.rear = 0;

    return temp;
}

void enQueue(QUEUE *q, int input) {
    q->queue[q->rear] = input;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    return;
}

int deQueue(QUEUE *q) {
    int dataToReturn = q->queue[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    return dataToReturn;
}

bool isEmpty(QUEUE q) {
    if (q.rear == q.front)
        return true;
    else    
        return false;
}

bool isFull(QUEUE q) {
    if (q.front == (q.rear + 1) % QUEUE_SIZE)
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
    if (isFull(test))
        printf("Is full\n");
    
    for (int i = test.front; i != test.rear; i = (i + 1) % QUEUE_SIZE) {
        number = deQueue(&test);
        printf("%d\n", number);
    }
    if (isEmpty(test))
        printf("Is empty\n");

    return 0;
}