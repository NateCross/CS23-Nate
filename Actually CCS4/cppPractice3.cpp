#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} NODE;

void doublePointerTest(node **dblPnter, node *sngPnter) {
    node **head = dblPnter;
    cout << "head: " << head << endl;
    cout << "*head: " << *head << endl;
    cout << "head data: " << (*head)->data << endl;
    cout << "head next: " << (*head)->next << endl;
    cout << "deref data: " << &((*head)->next) << endl;
    cout << "head->next" << endl;
    head = &((*head)->next);
    cout << "head: " << head << endl;
    cout << "*head: " << *head << endl;
    cout << "head data: " << (*head)->data << endl;
    cout << "head next: " << (*head)->next << endl;
    cout << "deref data: " << &((*head)->next) << endl;
    cout << "head->next" << endl;
    head = &((*head)->next);
    cout << "head: " << head << endl;
    cout << "*head: " << *head << endl;
    cout << "head data: " << (*head)->data << endl;
    cout << "head next: " << (*head)->next << endl;
    cout << "deref data: " << &((*head)->next) << endl;

    return;
}

void addNode (node **head, int input) {
    node **curr = head;
    cout << "address of curr: " << *curr << endl;
    while (*curr && input > (*curr)->data) {
        cout << "curr data: " << (*curr)->data << endl;
        curr = &((*curr)->next);
        // *curr = (*curr)->next;
    }
    node *temp = (struct node *) malloc(sizeof(struct node));
    temp->next = *curr;
    temp->data = input;
    *curr = temp;
    cout << "added at address: " << *curr << endl;
    return;

}

int main() {
    // node *testPointer = (struct node *)malloc(sizeof(struct node));
    // testPointer->next = (struct node *)malloc(sizeof(struct node));
    // testPointer->data = 1;
    // testPointer->next->data = 2;
    // testPointer->next->next = (struct node *)malloc(sizeof(struct node));
    // testPointer->next->next->data = 3;

    // doublePointerTest(&testPointer, testPointer);
    // free(testPointer->next->next);
    // free(testPointer->next);
    // free(testPointer);
    node *test = NULL;
    addNode(&test, 5);
    addNode(&test, 3);
    addNode(&test, 2);
    addNode(&test, 4);
    cout << test->data << test->next->data << test->next->next->data << test->next->next->next->data << endl;
    cout << "addresses:" << endl;
    cout << test << endl << test->next << endl << test->next->next << endl;
    return 0;
}