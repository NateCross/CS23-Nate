#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

typedef struct node *Node;
struct node {
    int data;
    Node left, right;
} BinarySearch;

void addNode(Node *tree, int input) {
    Node newNode = malloc(sizeof(BinarySearch));
    newNode->data = input;
    newNode->left = NULL;
    newNode->right = NULL;
    //printf("%d\n", newNode->data);

    Node temp = *tree, temp2 = temp;

    if (temp == NULL)
        *tree = newNode;

    else {
        while (temp2 != NULL) {
            if (temp2->data >= input) {
                temp = temp2;
                temp2 = temp2->left;
            }
            else {
                temp = temp2;
                temp2 = temp2->right;
            }
        }
        //if (temp2 == NULL)
            //printf("temp2 is null\n");
        //printf("temp: %d\tinput: %d\n", temp->data, input);

        if (temp->data >= input)
            temp->left = newNode;
        else
            temp->right = newNode;
    }


    /*
    if (input == 15)
        temp->right = newNode;
    else if (input == 1) {
        //temp->right->right = newNode;
        temp = temp->right;
        temp->right = newNode;
    }


    else
        temp->left = newNode;
    //temp->data = input;

    */
    //printf("%d\n", temp->data);
}

void printTree(Node tree) {
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        printTree(tree->left);

    printf("%d ", tree->data);

    if (tree->right != NULL)
        printTree(tree->right);
}

void reverseTree(Node *tree) {
    if (temp == NULL)
        return;

    Node temp = *tree;

    if (temp->left != NULL)
        reverseTree(&temp->left);

    if (temp->right != NULL)
        reverseTree(&temp->right);

    Node switchTemp = temp->left;
    temp->left = temp->right;
    temp->right = switchTemp;
}

int main() {
    int numberData[SIZE] = {7, 15, 1, 17, 15, 10, 13, 11, 12, 3, 17, 19, 4, 19, 7};
    Node test = NULL;
    for (int i = 0; i < SIZE; i++)
        addNode(&test, numberData[i]);


    /*
    Node test = malloc(sizeof(BinarySearch));
    Node a = malloc(sizeof(BinarySearch));
    Node b = malloc(sizeof(BinarySearch));
    a->data = 6;
    b->data = 7;
    */

    //test->data = 5;
    //test->left = a;
    //test->right = b;
    //printf("%d %d %d %d\n", test->data, test->data, test->data, test->data);
    //printf("%d %d %d %d\n", test->left->data, test->right->data, test->right->right->data, test->right->left->data);
    printTree(test);

    reverseTree(&test);
    printf("\n");
    printTree(test);

}
