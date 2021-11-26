#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node *node;
struct node {
    unsigned int priority;
    node next;
} PRIO_QUEUE;

node initialize_queue() {
    node temp;
    temp = NULL;
    return temp;
}

void push(node *queue, int input) {

    // Creating the node for insertion by allocating memory
    node temp = malloc(sizeof(PRIO_QUEUE));
    temp->priority = input;
    temp->next = NULL;

    int prioTemp;

    // Mark for insertion
    // node queueMarker1 = *queue;

    if (*queue != NULL) {
        // if (queueMarker->priority > input)
        // while (queueMarker1->priority > input) {
            // queueMarker1 = queueMarker1->next;
            // if (queueMarker1 == NULL || queueMarker1->priority <= input)
        // }
        // while (queueMarker1->next != NULL) {
            // if (queueMarker1->priority > input) {}
        // }
        // temp->next = queueMarker1;
        
        temp->next = *queue;
        // Used as a marker to traverse through the linked list
        node temp1 = temp;

        // This method seems to use the least amount of code but is still 
        // O(n) time. Here, we place the temp for insertion at the head, 
        // then we compare if it is lesser than what's next. If it is, we swap.
        while (temp1->next != NULL) {

            // Swap between the current and next priority if lesser
            if (temp1->priority < temp1->next->priority) {
                prioTemp = temp1->next->priority;
                temp1->next->priority = temp1->priority;
                temp1->priority = prioTemp;
            }
            // node temp2 = temp;

            temp1 = temp1->next;
        }
    }
    *queue = temp;
    
    return;
}

int pop(node *queue) {
    node temp = *queue;
    int dataToReturn = temp->priority;
    *queue = (*queue)->next;
    free (temp);
    return dataToReturn;
}

void print_queue(node queue) {
    printf("Queue: \n");
    while (queue != NULL) {
        printf("%d\n", queue->priority);
        queue = queue->next;
    }

    return;
}

int main() {
    node test = initialize_queue();
    push(&test, 2);
    push(&test, 1);
    push(&test, 6);
    push(&test, 3);
    push(&test, 4);
    print_queue(test);
    int returned = pop(&test);
    printf("\nReturned value: %d\n", returned);
    print_queue(test);
    
    return 0;
}
