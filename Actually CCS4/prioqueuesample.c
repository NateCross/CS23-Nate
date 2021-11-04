#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node *nd;
struct node {
    int data;
    nd left;
    nd right;
} NODE;

nd insertNode(nd node, int input) {
    if (node == NULL) {
        nd temp = (nd)malloc(sizeof(NODE));
        temp->data = input;
        temp->left = NULL;
        temp->right = NULL;

        node = temp;
    }  

    return node; // Base case
}

int main() {
    printf("test");

    _getch();
    return 0;
}
