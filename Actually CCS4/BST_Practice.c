#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *nd;
struct node {
    int data;
    nd left;
    nd right;
} NODE;

void insertNode (nd *root, int input) {
    nd temp = malloc(sizeof(NODE));
    temp->data = input;
    temp->left = NULL;
    temp->right = NULL;

    nd ptr = *root, ptr1;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ptr1 = ptr;
            if (temp->data < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (temp->data < ptr1->data)
            ptr1->left = temp;
        else
            ptr1->right = temp;
    }
    else
        *root = temp;
    return;
}

void printAllNodes (nd tree) {
    if (tree != NULL) {
        printAllNodes(tree->left);
        printf("%d ", tree->data);
        printAllNodes(tree->right);
    }
    return;
}

int getMinimum (nd tree) {
    if (tree->left != NULL)
        return getMinimum(tree->left);
    else
        return tree->data;
}

int getMaximum (nd tree) {
    if (tree->right != NULL)
        return getMaximum(tree->right);
    else
        return tree->data;
}

nd insertNodeRecursion (nd tree, int input) {
    if (tree == NULL) {
        tree = malloc(sizeof(NODE));
        tree->data = input;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }

    if (input < tree->data)
        tree->left = insertNodeRecursion(tree->left, input);
    else
        tree->right = insertNodeRecursion(tree->right, input);

    return tree;
}

bool searchDelete(nd *ptr, nd *ptr1, int key) {
    while (*ptr != NULL) {
        if (key == (*ptr)->data)
            return true;
        *ptr1 = *ptr;
        if (key < (*ptr)->data)
            *ptr = (*ptr)->left;
        else
            *ptr = (*ptr)->right;
    }
    return false;
}

bool deleteLeaf(nd *ptr, nd *ptr1, nd **root) {
    if (*ptr == **root)
        **root = NULL;
    else {
        if ((*ptr1)->left == *ptr)
            (*ptr1)->left = NULL;
        else
            (*ptr1)->right = NULL;
    }
    free(*ptr);

    return true;
}

bool deleteOneChild(nd *ptr, nd *ptr1, nd *root) {
    if (*ptr == *root) {
        if ((*root)->left != NULL)
            *root = (*root)->left;
        else
            *root = (*root)->right;
    }
    else {
        if ((*ptr1)->left == *ptr) {
            if ((*ptr)->left != NULL)
                (*ptr1)->left = (*ptr)->left;
            else
                (*ptr1)->left = (*ptr)->right;
        }
        else {
            if ((*ptr)->left != NULL)
                (*ptr1)->right = (*ptr)->left;
            else
                (*ptr1)->right = (*ptr)->right;
        }
    }
    free(*ptr);
    return true;
}

bool deleteTwoChildren(nd *ptr, nd *ptr1) {
    nd ptr2 = NULL;
    *ptr1 = (*ptr)->right;
    while ((*ptr1)->left != NULL) {
        ptr2 = *ptr1;
        *ptr1 = (*ptr1)->left;
    }
    (*ptr)->data = (*ptr1)->data;
    if (ptr2 != NULL) {
        if ((*ptr1)->right != NULL)
            ptr2->left = (*ptr1)->right;
        else
            ptr2->left = NULL;
    }
    else {
        if ((*ptr1)->right != NULL)
            (*ptr)->right = (*ptr1)->right;
        else
            (*ptr)->right = NULL;
    }
    free(*ptr1);
    return true;
}

void deleteProcedure(nd *root, int key) {
    nd ptr = *root, ptr1;
    bool isDeleted;

    if (searchDelete(&ptr, &ptr1, key)) {
        if (ptr->left == NULL && ptr->right == NULL)
            isDeleted = deleteLeaf(&ptr, &ptr1, &root);
        else if (ptr->left != NULL && ptr->right != NULL)
            isDeleted = deleteTwoChildren(&ptr, &ptr1);
        else
            isDeleted = deleteOneChild(&ptr, &ptr1, root);
    }
    else
        printf("\nNot found.\n");
    return;
}

int main() {
    nd test = NULL;
    insertNode(&test, 1);
    insertNode(&test, 5);
    insertNode(&test, -1);
    insertNode(&test, -3);
    insertNode(&test, -5);
    insertNodeRecursion(test, 7);
    insertNodeRecursion(test, 4);
    deleteProcedure(&test, 1);
    deleteProcedure(&test, 5);
    deleteProcedure(&test, -1);
    deleteProcedure(&test, -3);
    deleteProcedure(&test, -5);
    deleteProcedure(&test, 7);
    //deleteProcedure(&test, 4);
    printAllNodes(test);

    // int number = getMinimum(test);
    // printf("\n%d", number);
    // deleteProcedure(&test, 7);
    // number = getMaximum(test);
    // printf("\n%d", number);

    return 0;
}