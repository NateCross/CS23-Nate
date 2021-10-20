// This program models a simple store inventory system implemented through a
// Binary Search Tree (BST). This data structure allows for efficient sorting
// and retrieval of data.
// It is designed to track item inventory, customers, and sales. 
// These sets of data have their own BST, 
// and in each tree they are arranged by their respective number.

// Author: Nathan Angelo B. Cruz

// Started: 2021/10/17
// Finished: 2021/10/19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#include "CruzBSTshared.h"
#include "CruzBSTitem.h"
#include "CruzBSTcustomer.h"
#include "CruzBSTsales.h"

char menu() {
    char input;

    system("cls");
    printf("\tCruz Enterprise\n");
    printf("\t1] Add New Item\n");
    printf("\t2] Add New Customer\n");
    printf("\t3] Delete an Item\n");
    printf("\t4] Sales\n");
    printf("\t5] Display All Items\n");
    printf("\t6] Exit\n");
    printf("\tEnter choice: ");
    scanf("%c", &input);
    fflush(stdin);

    return input;
}

void storeOperation() {
    ndItem treeItem = NULL;
    ndCust treeCust = NULL;
    ndSale treeSale = NULL;
    char choice;

    do {
        choice = menu();

        switch (choice) {
            case '1':
                insertItem(&treeItem);
                break;
            case '2':
                insertCustomer(&treeCust);
                break;
            case '3':
                deleteItemProcedure(&treeItem);
                break;
            case '4':
                insertSale(&treeSale, &treeItem);
                break;
            case '5':
                initializeDisplayAllItems(treeItem);
                break;
            case '6':
                break;
            default:
                printf("\tError: Invalid input.\n");
                printf("\tPress any key to continue.\n");
                getch();
                break;
        }
    } while (choice != '6');
}

int main() {
    storeOperation();

    printf("\n\tExiting program...\n");
    printf("\tPress any key to end.\n");
    getch();
    return 0;
}


