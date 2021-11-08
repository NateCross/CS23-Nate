#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

#define S 10

typedef struct {
    int pQueue[S];
    int size;
} PRIORITY_QUEUE;

bool isFull(PRIORITY_QUEUE heap) {
    if (heap.size == S - 1)
        return true;
    else
        return false;
}

bool isEmpty(PRIORITY_QUEUE heap) {
    if (heap.size == 0)
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
            i /= 2;     
        }
        heap->pQueue[i] = input;
    }
    return;
}

void swap(int *i, int *smaller) {
    int temp = *i;
    *i = *smaller;
    *smaller = temp;
    return;
}

void heapify(int i, PRIORITY_QUEUE *heap) {
    int smaller, left = i * 2, right = i * 2 + 1;

    // These are to check which one among i and its children is the smallest
    if (left <= heap->size && heap->pQueue[left] < heap->pQueue[i])
        smaller = left;
    else
        smaller = i;
    if (right <= heap->size && heap->pQueue[right] < heap->pQueue[smaller])
        smaller = right;

    if (smaller != i) {
        swap(&heap->pQueue[i], &heap->pQueue[smaller]);
        heapify(smaller, heap);
    }
    return;
}

PRIORITY_QUEUE heapifyRecursive(int i, PRIORITY_QUEUE heap) {
    int smaller, left = i * 2, right = i * 2 + 1;
    
    if (left <= heap.size && heap.pQueue[left] < heap.pQueue[i])
        smaller = left;
    else
        smaller = i;
    if (right <= heap.size && heap.pQueue[right] < heap.pQueue[smaller])
        smaller = right;

    if (smaller != i) {
        swap(&heap.pQueue[i], &heap.pQueue[smaller]);
        heap = heapifyRecursive(smaller, heap);
    }

    return heap;
}

int heapDeleteMin(PRIORITY_QUEUE *heap) {
    int min = heap->pQueue[1];
    heap->pQueue[1] = heap->pQueue[heap->size];
    heap->size--;
    
    // heapify(1, heap);
    *heap = heapifyRecursive(1, *heap);
    
    return min;
}

void printQueue(PRIORITY_QUEUE heap) {
    for (int i = 1; i <= heap.size; i++)
        printf("%d ", heap.pQueue[i]);
    return;
}

void buildHeap(PRIORITY_QUEUE *heap) {
    for (int i = heap->size / 1; i >= 1; i--) {
        heapify(i, heap);
    }
    return;
}

int main() {
    char           choice[100];
    int            input;
    PRIORITY_QUEUE lmao        = initializeQueue();
    while (true) {
        system("cls");
        printQueue(lmao);
        printf("\nCommands:\n");
        printf("del - delete minimum\n");
        printf("q - quit\n");
        printf("build - build heap\n");
        printf("any number - insert\n");
        printf("\nEnter command: ");

        // Proper way to do gets from now on; 
        // without strcspn inputs aren't clean and program won't work
        fgets(choice, 100, stdin);
        choice[strcspn(choice, "\n")] = 0;

        if (strcmp(choice, "del") == 0) 
            heapDeleteMin(&lmao);
        else if (strcmp(choice, "q") == 0)
            break;
        else if (strcmp(choice, "build") == 0)
            buildHeap(&lmao);
        else {
            input = atoi(choice);
            insert(input, &lmao);
        }
    }

    printf("Press any key to end.\n");
    _getch();
    return 0;
}
