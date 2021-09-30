#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
struct node {
    int data;
    Node next;
} Queue;

void createQueue(Node *temp) {
    *temp = NULL;
}

void enqueue(Node *rear, int input) {
    Node temp = malloc(sizeof(Node));
    temp->data = input;
    temp->next = NULL;
    if (*rear != NULL) {
        (*rear)->next = temp;
    }
    *rear = temp;
    return;
}

int dequeue(Node *front) {
    Node temp = *front;
    int output = (*front)->data;
    (*front) = (*front)->next;
    free(temp);

    return output;
}

void queueOperation() {
    //Node testRear = createQueue();
    Node testRear;
    createQueue(&testRear);
    enqueue(&testRear, 5);
    //Node temp = malloc(sizeof(Node));
    //temp->data = 3;
    //testRear->next = temp;
    if (testRear==NULL)
        printf("Lol\n");
    //printf("%d\n", testRear->next->data);
    printf("%d\n", testRear->data);
    enqueue(&testRear, 6);
    printf("%d\n", testRear->data);

}

int main() {
    queueOperation();

    /*
    Node test = malloc(sizeof(Node));
    test->data = 5;
    printf("%d", test->data);
    */
}
