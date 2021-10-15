/*
You are looking at Nate's jank practice.
I am just stress testing everything to get it working.
Will clean up sometime.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char studName[50];
    int studID;
} STUD;

typedef struct node *nd;
struct node {
    nd left, right;
    STUD student;
} NODE;

void createNode(int *id, char *name) {
    int tempID;
    char tempName[50];

    printf("Input ID: ");
    scanf("%d", &tempID);
    printf("Input Name: ");
    fflush(stdin);
    gets(tempName);

    *id = tempID;
    strcpy(name, tempName);

    return;
}

bool searchNode(nd *ptr, nd *ptr1, int key) {
    if ((*ptr)->student.studID == key)
        return true;

    while ((*ptr)->student.studID != key) {
        *ptr1 = *ptr;
        if (key <= (*ptr)->student.studID)
            *ptr = (*ptr)->left;
        else
            *ptr = (*ptr)->right;

        if (*ptr == NULL)
            return false;
    }
    //printf("%d\n", ptr->student.studID);
    return true;  // Must catch error if NULL is returned.
}

void insertNode(nd *root) {
    int id;
    char name[50];
    createNode(&id, name);
    nd temp = malloc(sizeof(NODE));
    temp->student.studID = id;
    strcpy(temp->student.studName, name);
    temp->left = NULL;
    temp->right = NULL;

    nd ptr = *root, ptr1;

    if (*root != NULL) {
        ptr = *root;
        if (searchNode(&ptr, &ptr1, id)) {
            printf("Node exists. Please input a new node.\n");
            printf("Press any key to continue.\n");
            getch();
            return;
        }
        ptr = *root;
        while (ptr != NULL) {
            ptr1 = ptr;
            if (id <= ptr->student.studID)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        if (id <= ptr1->student.studID)
            ptr1->left = temp;
        else
            ptr1->right = temp;
    }
    else
        *root = temp;

    return;
}


/*
nd searchNode(nd *root, int key) {  // Used for print and edit; not delete
    nd ptr = *root, ptr1;
    printf("%d\n", ptr->right->student.studID);

    if (ptr->student.studID == key)
        return ptr;

    while (ptr != NULL) {
        ptr1 = ptr;
        if (key <= ptr->student.studID)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    //printf("%d\n", ptr->student.studID);
    return ptr1;  // Must catch error if NULL is returned.
}
*/

int inputSearchkey() {
    int searchKey;
    printf("Input ID: ");
    scanf("%d", &searchKey);

    return searchKey;
}

bool deleteLeaf(nd *ptr, nd *ptr1, nd *root) {
    if (*ptr == *root) {
        *root = NULL;
    }
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
    //printf("ptr: %d root: %d\n", (*ptr)->student.studID, (*root)->student.studID);
    if (*ptr == *root) {
        //printf("ptr == root\n");
        if ((*ptr)->left != NULL) {
            *root = (*root)->left;
            //*ptr = (*ptr)->left;
            //printf("ptr left\n");
        }
        else {
            *root = (*root)->right;
            //*ptr = (*ptr)->right;
            //printf("ptr right\n");
        }
        //printf("ptr: %d root: no\n", (*ptr)->student.studID);
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

    (*ptr)->student = (*ptr1)->student;

    if (ptr2 != NULL) {
        if ((*ptr1)->right != NULL) {
            ptr2->left = (*ptr1)->right;
            //printf("PTR1 not null\n");
        }
        else
            ptr2->left = NULL;
    }
    else {
        if ((*ptr1)->right != NULL)
            (*ptr)->right = (*ptr1)->right;
        else
            (*ptr)->right = NULL;
    }

    *ptr1 = NULL;
    free(*ptr1);

    return true;
}


void deleteProcedure(nd *root) {
    if (*root == NULL) {
        printf("Tree is empty.\n");
        printf("Press any key to continue.\n");
        getch();
        return;
    }

    nd ptr = *root, ptr1;
    bool isDeleted;
    int searchKey = inputSearchkey();

    if (searchNode(&ptr, &ptr1, searchKey)) {
        if (ptr->left == NULL && ptr->right == NULL)
            isDeleted = deleteLeaf(&ptr, &ptr1, root);
        else if (ptr->left != NULL && ptr->right != NULL)
            isDeleted = deleteTwoChildren(&ptr, &ptr1);
        else
            isDeleted = deleteOneChild(&ptr, &ptr1, root);
    }
    printf("Node deleted.\n");
    printf("Press any key to continue.\n");
    getch();
    return;
}

void printNode(nd *tree) {
    if (*tree == NULL) {
        printf("Tree is empty.\n");
        printf("Press any key to continue.\n");
        getch();
        return;
    }

    nd ptr = *tree, ptr1;
    int input = inputSearchkey();
    //system("cls");
    //nd nodeToPrint = searchNode(&ptr, input);
    bool nodeExists = searchNode(&ptr, &ptr1, input);
    if (nodeExists) {
        printf("Student ID: %d\n", ptr->student.studID);
        printf("Student Name: %s\n", ptr->student.studName);
    }
    else
        printf("Invalid input. Try again.\n");
    printf("Press any key to continue.\n");
    getch();
    return;
}

void editNode(nd *tree) {
    if (*tree == NULL) {
        printf("Tree is empty.\n");
        printf("Press any key to continue.\n");
        getch();
        return;
    }

    char newName[50];
    nd ptr = *tree, ptr1;
    int input = inputSearchkey();
    bool nodeExists = searchNode(&ptr, &ptr1, input);
    if (nodeExists) {
        printf("Current Name: %s\n", ptr->student.studName);
        printf("Please input new name: ");
        fflush(stdin);
        gets(newName);
        strcpy(ptr->student.studName, newName);
        printf("Name changed.\n");
    }
    else
        printf("Invalid input. Try again.\n");
    printf("Press any key to continue.\n");
    getch();
    return;
}

void printAllIDs(nd tree) {
    nd ptr = tree;
    if (ptr != NULL) {
        printAllIDs(ptr->left);
        printf("%d ", ptr->student.studID);
        printAllIDs(ptr->right);
    }
}



void menu(nd *tree) {
    int input, input2;
    do {
        system("cls");
        fflush(stdin);

        printf("IDs: ");
        printAllIDs(*tree);
        printf("\n\n");
        printf("1. Display student name\n");
        printf("2. Edit student name\n");
        printf("3. Add student\n");
        printf("4. Delete student\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &input);
        printf("\n");
        switch (input) {
            case 1:
                printNode(tree);
                break;
            case 2:
                editNode(tree);
                break;
            case 3:
                insertNode(tree);
                break;
            case 4:
                deleteProcedure(tree);
            case 0:
                break;
            default:
                printf("Invalid input. Try again.\n");
                getch();
                break;
        }
    } while (input != 0);
}

int main() {
    nd nice = NULL;
    /*
    insertNode(&nice, 2, "pee");
    insertNode(&nice, 3, "poo");
    insertNode(&nice, 1, "okay");

    insertNode(&nice, 5, "lmao");
    insertNode(&nice, 4, "haha");
    insertNode(&nice, 10, "a");
    insertNode(&nice, 20, "b");
    insertNode(&nice, 6, "c");
    insertNode(&nice, 7, "d");
    */
    menu(&nice);

    /*
    printf("Student ID: %d\n", nice->student.studID);
    printf("Student Name: %s\n", nice->student.studName);
    printf("Student ID: %d\n", nice->right->student.studID);
    printf("Student Name: %s\n", nice->right->student.studName);
    */
    /*
    deleteProcedure(&nice);
    //deleteProcedure(&nice);

    while (true)
        printNode(&nice);

    getch();
    */
}
