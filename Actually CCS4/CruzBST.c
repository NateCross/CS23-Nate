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

void storeOperation() {
    ndItem listItem = NULL;
    ndCust listCust = NULL;
    ndSale listSales = NULL;
    char choice;

    do {
        choice = menu();

        switch (choice) {
            case '1':
                insertItem(&listItem);
                break;
            case '2':
                insertCustomer(&listCust);
                break;
            case '3':
                deleteItemProcedure(&listItem);
                break;
            case '4':
                insertSale(&listSales, &listItem);
                break;
            case '5':
                initializeDisplayAllItems(listItem);
                break;
            case '6':
                break;
            default:
                printf("Error: Invalid input.\n");
                printf("Press any key to continue.\n");
                getch();
                break;
        }
    } while (choice != '6');
}

int main() {
    storeOperation();

    printf("\nExiting program...\n");
    printf("Press any key to end.\n");
    getch();
    return 0;
}


