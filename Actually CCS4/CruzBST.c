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
    char key[4];
    ITEM itemToAdd;
    CUSTOMER custToAdd;
    SALES saleToAdd;

    do {
        choice = menu();

        switch (choice) {
            case '1':
                if (createItem(&itemToAdd))
                    insertItem(&listItem, itemToAdd);
                break;
            case '2':
                if (createCustomer(&custToAdd))
                    insertCustomer(&listCust, custToAdd);
                break;
            case '3':
                if (inputSearchKey(key))
                    deleteItemProcedure(&listItem, key);
                break;
            case '4':
                if (createSale(&saleToAdd))
                    insertSale(&listSales, saleToAdd, &listItem);
                break;
            case '5':
                initializeDisplayAllItems(listItem);
                break;
            case '6':
                break;
            case '7': // TODO: DELETE AFTER
                system("cls");
                displayAllCustomers(listCust);
                getch();
                break;
            case '8': // TODO: DELETE AFTER
                system("cls");
                displayAllSales(listSales);
                getch();
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
    return 0;
}


