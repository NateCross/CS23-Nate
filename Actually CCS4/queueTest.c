#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Queue {
    int data[SIZE];
    int front;
    int rear;
} Queue;

Queue createQueue() {
    Queue q;
    q.front = 0;
    q.rear = -1;

    return q;
}

void enqueue(Queue *q, int input) {
    q->data[q->front] = input;
    if (q->front < SIZE)
        q->front++;
}

void dequeue(Queue *q) {
    if (q->rear != -1)
        q->data[q->rear] = NULL;
    q->rear++;
}

void printFullQueue(Queue q) {
    int *looper = q.data;
    while (*looper) {
        printf("%d\n", *looper);
        *looper++;
    }
    return;
}

int main() {
    Queue test1 = createQueue();
    printf("test1.front: %d\n", test1.front);
    enqueue (&test1, 1);
    enqueue (&test1, 2);
    printFullQueue (test1);
}
