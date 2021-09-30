#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
struct node {
    int data;
    Node next;
} Nodes;

typedef struct {
    Node front, back;
} Queues;

void testQueue(Queues *lmaolmao) {
    lmaolmao->front->data = 7;
}

void testPrint(Queues *lmao) {
    printf("\n%d\n", lmao->front->data);
    printf("%d\n", lmao);
    //printf("%d\n", *lmao);
    testQueue(lmao);
    printf("\n%d", lmao->front->data);
}



int main() {
    Queues test;
    test.front = NULL;
    if (test.front == NULL)
        printf("lol");
    test.front = malloc(sizeof(Node));
    test.front->data = 5;
    printf("%d\n", test.front->data);
    printf("%d\n", &test);
    testPrint(&test);

    return 0;
}
