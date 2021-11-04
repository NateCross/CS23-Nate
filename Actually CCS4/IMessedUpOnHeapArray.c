// TODO: Add heapify function

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define S 10

typedef struct {
    int pQueue[S];
    int size;
} PRIORITY_QUEUE;

bool isFull (PRIORITY_QUEUE heap) {
    if (heap.size == S)
        return true;
    else
        return false;
}

PRIORITY_QUEUE initializeQueue() {
    PRIORITY_QUEUE temp;
    temp.pQueue[0] = 0;     // Must set to 0 else this won't work in C
    temp.size = 0;
    return temp;
}

void insert(int input, PRIORITY_QUEUE *heap) {
    unsigned int i;     // Serves as an index
    if (isFull(*heap))
        return;     // Generate error message here
    else {
        i = ++heap->size;    // So it starts at 1 and not 0, also auto increments
        while (heap->pQueue[i/2] > input) {
            heap->pQueue[i] = heap->pQueue[i/2];
            i = i >> 1;     // Divide i by 2, but cheaper and sexier
        }
        heap->pQueue[i] = input;
    }
    return;
}

int heapDeleteMin(PRIORITY_QUEUE *heap) {
    int min = heap->pQueue[1];
    heap->pQueue[1] = heap->pQueue[heap->size];
    heap->size--;
    // heapify(1, *heap);
    
    return min;
}

void printQueue(PRIORITY_QUEUE heap) {
    for (int i = 1; i <= heap.size; i++)
        printf("%d ", heap.pQueue[i]);
    return;
}

int main() {
    int test = 5;
    PRIORITY_QUEUE lmao = initializeQueue();
    insert(10, &lmao);
    insert(5, &lmao);
    insert(15, &lmao);
    insert(1, &lmao);
    insert(3, &lmao);

    printQueue(lmao);

    _getch();
    return 0;
}
