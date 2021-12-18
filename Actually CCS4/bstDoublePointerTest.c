// This is the super hack for linked list-type programs
// It uses double pointers to simplify the program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node * initBST() {
    node *temp;
    temp = NULL;
    return temp;
}

// BST double pointer secret Discord tech???
void insertNode(node **root, int input) {
    node **curr = root;

    node *temp = malloc(sizeof(node));
    temp->data = input;
    temp->left = NULL;
    temp->right = NULL;

    while (*curr) {
        if (input < (*curr)->data)
            curr = &(*curr)->left;
        else
            curr = &(*curr)->right;
    }

    *curr = temp;

    return;
}

node ** searchNode(node **ptr, int key) {
    bool found = false;
    while (*ptr) {
        if (key < (*ptr)->data)
            ptr = &((*ptr)->left);
        else if (key > (*ptr)->data)
            ptr = &((*ptr)->right);
        else {
            found = true;
            break;
        }
    }
    return ptr;
}

bool deleteLeaf(node **del) {
    node *temp = *del;
    *del = NULL;
    free(temp);
    return true;
}

bool deleteOneChild(node **del) {
    node *temp = *del;
    if ((*del)->left)
        *del = (*del)->left;
    else
        *del = (*del)->right;
    free(temp);
    return true;
}

bool deleteTwoChildren(node **del) {
    node **ptr = &(*del)->right;
    while ((*ptr)->left != NULL)
        ptr = &(*ptr)->left;
    (*del)->data = (*ptr)->data;
    node *temp = *ptr;
    *ptr = (*ptr)->right;
    free(temp);
    return true;
}

void deleteProcedure(node **root, int key) {
    node **ptr = root;
    node **test = searchNode(ptr, key);
    if (!(*test)) {
        return;
    }

    if ((*test)->left == NULL && (*test)->right == NULL)
        deleteLeaf(test);
    else if ((*test)->left != NULL && (*test)->right != NULL)
        deleteTwoChildren(test);
    else
        deleteOneChild(test);

    return;
}

void printAll(node *tree) {
    if (tree) {
        printAll(tree->left);
        printf("%d ", tree->data);
        printAll(tree->right);
    }
    return;
}

int main() {
    node *test = initBST();
    insertNode(&test, 5);
    insertNode(&test, 3);
    insertNode(&test, 7);
    insertNode(&test, 9);
    insertNode(&test, 1);
    insertNode(&test, 2);

    // deleteProcedure(&test, 9);
    // deleteProcedure(&test, 2);
    // deleteProcedure(&test, 1);
    deleteProcedure(&test, 5);
    deleteProcedure(&test, 3);
    deleteProcedure(&test, 1);
    deleteProcedure(&test, 2);
    deleteProcedure(&test, 7);
    deleteProcedure(&test, 8);
    // deleteProcedure(&test, 5);

    printAll(test);
    printf("\ndone\n");

    return 0;

}