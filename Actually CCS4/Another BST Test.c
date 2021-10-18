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

typedef struct {
    char number[4];
    char name[30];
    int quantity;
    float price;
} ITEM;

typedef struct {
    char number[4];
    char name[40];
} CUSTOMER;

// typedef struct {
    
// } SALES;

typedef struct node *nd;
struct node {
    ITEM item;
    CUSTOMER cust;
    // SALES sales;
    nd left, right;
} NODE;

nd createNode(int type) {
    nd temp = malloc(sizeof(NODE));
    temp->left = NULL;
    temp->right = NULL;

    switch (type) {
        case 0: // Item
            char numberInput[4], nameInput[30]; // Reverse into inputNumber?
            int quantityInput;
            float priceInput;

            fflush(stdin);
            printf("Input item number (XXXX format): ");
            gets(numberInput);
            fflush(stdin);
            printf("Input item name: ");
            gets(nameInput);
            fflush(stdin);
            printf("Input item quantity: ");
            scanf("%d", &quantityInput);
            printf("Input item price: ");
            scanf("%f", &priceInput);

            strcpy(temp->item.number, numberInput);
            strcpy(temp->item.name, nameInput);
            temp->item.quantity = quantityInput;
            temp->item.price = priceInput;
            break;
    }

    return temp;
}

void insertNode(nd *root, int type) {

}

int main() {
    nd inventory, customers;
}