/*
Nathan Angelo B. Cruz

This program models a store inventory system implemented through a
Binary Search Tree.

Start Date: 2021/10/17
End Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include "CruzBSTitem.h"

// typedef struct {
//     char number[4];
//     char name[40];
// } CUSTOMER;

// TODO
// typedef struct {
    
// } SALES;

// typedef struct node_customer *ndCust;
// struct node_customer {
//     CUSTOMER cust;
//     ndCust left;
//     ndCust right;
// } TREE_CUSTOMER;

// typedef struct node

//DONE inputSearchKey - for deletion
//searchItem, return the node, also when using sales, for subtracting qty
//createItem, create struct item
//insertItem
//deleteItemProcedure
//deleteItemLeaf
//deleteItemOneChild
//deleteItemTwoChildren
//printItem - for deletion

//createCustomer - input all the fields
//insertCustomer

//createSale
//insertSale

//displayAllItems


char menu() {
    char input;

    system("cls");
    printf("Cruz Enterprise\n");
    printf("1] Add New Item\n");
    printf("2] Add New Customer\n");
    printf("3] Delete an Item\n");
    printf("4] Sales\n");
    printf("5] Display All Items\n");
    printf("6] Exit\n");
    printf("Enter choice: ");
    scanf("%c", &input);
    fflush(stdin);

    return input;
}

void inputSearchKey(char *search) {
    printf("Input entry number: ");
    gets(search);
    fflush(stdin);
    return;
}

void storeOperation() {
    ndItem listItem = NULL;
    // ndCust listCust;
    char choice;
    char key[4];
    ITEM itemToAdd;
    // CUSTOMER custToAdd
    // SALES saleToAdd

    do {
        choice = menu();

        switch (choice) {
            case '1':
                itemToAdd = createItem();
                insertItem(&listItem, itemToAdd);
                break;
            case '2':
                //  = createCustomer();
                // insertCustomer(&listCust, custToAdd);
                break;
            case '3':
                inputSearchKey(key);
                // deleteItemProcedure(&listItem, key);
                break;
            case '4':
                //  = createSales();
                // insertSale(&listSale, saleToAdd);
                break;
        }

    } while (choice != '6');

}

void displayAllItems(ndItem tree) {
    ndItem ptr = tree;
    if (ptr != NULL) {
        displayAllItems(ptr->left);
        // TODO: insert print here
        displayAllItems(ptr->right);
    }
}

int main() {
    // ndItem test;
    // test = malloc(sizeof(TREE_ITEM));
    // strcpy(test->item.number, "69");
    // printf("%s\n", test->item.number);

    // ndCust test1;
    // test1 = malloc(sizeof(TREE_CUSTOMER));
    // strcpy(test1->cust.number, "21");
    // printf("%s\n", test1->cust.number);
    
    storeOperation();
    

    return 0;
}


