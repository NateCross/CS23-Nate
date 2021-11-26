#ifndef SALE_H
#define SALES_H

#define SALES_NUMBER 7

typedef struct {
    int quantitySold;
    char itemNumber[ITEM_NUMBER];
    char custNumber[CUSTOMER_NUMBER];
    char number[SALES_NUMBER];
} SALES;

typedef struct node_sales *ndSale;
struct node_sales {
    SALES sale;
    ndSale left;
    ndSale right;
} TREE_SALE;

bool createSale(SALES *temp) {
    printf("\tEnter item number: ");
    gets(temp->itemNumber);
    fflush(stdin);
    if (strlen(temp->itemNumber) >= ITEM_NUMBER) {
        printf("\tError: Too many characters in number.\n");
        printf("\tPress any key to return.\n");
        getch();
        return false;
    }

    printf("\tEnter customer number: ");
    gets(temp->custNumber);
    fflush(stdin);
    if (strlen(temp->custNumber) >= CUSTOMER_NUMBER) {
        printf("\tError: Too many characters in number.\n");
        printf("\tPress any key to return.\n");
        getch();
        return false;
    }

    printf("\tEnter quantity of items to be sold: ");
    scanf("%d", &temp->quantitySold);
    fflush(stdin);

    // Because number is empty, must strcpy first
    strcpy(temp->number, temp->itemNumber);
    strcat(temp->number, temp->custNumber);

    return true;
}

bool checkSaleValidity(SALES saleToCheck, ndItem *ptr, ndItem *ptr1) {
    if (!(searchItem(ptr, ptr1, saleToCheck.itemNumber))) {
        printf("\tError: Item number does not exist.\n");
        printf("\tPress any key to return.\n");
        getch();
        return false;
    }
    if ((*ptr)->item.quantity == 0) {
        printf("\tError: Item is out of stock.\n");
        printf("\tPress any key to return.\n");
        getch();
        return false;
    }
    if (saleToCheck.quantitySold < 0) {
        printf("\tError: Quantity sold to customer is negative.\n");
        printf("\tPress any key to return.\n");
        getch();
        return false;
    }
    return true;
}

void insertSale(ndSale *root, ndItem *itemRoot) {
    SALES saleToAdd;
    if (!createSale(&saleToAdd))
        return;

    ndItem itemPtr = *itemRoot, itemPtr1;
    if (!checkSaleValidity(saleToAdd, &itemPtr, &itemPtr1))
        return;

    ndSale temp = malloc(sizeof(TREE_SALE));
    temp->sale = saleToAdd;
    temp->left = NULL;
    temp->right = NULL;

    ndSale ptr = *root, ptr1;
    int comparison;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ptr1 = ptr;
            comparison = numberComparison(temp->sale.number, ptr->sale.number);
            
            if (comparison < 0)
                ptr = ptr->left;
            else if (comparison > 0)
                ptr = ptr->right;
            else {
                printf("\tError: Number already exists.\n");
                printf("\tPress any key to return.\n");
                getch();
                return;
            }
        }
        if (comparison < 0)
            ptr1->left = temp;
        else
            ptr1->right = temp;
    }
    else
        *root = temp;
    
    itemPtr->item.quantity -= temp->sale.quantitySold;

    printf("\tSale successfully added.\n");
    printf("\tPress any key to return.\n");
    getch();
    return;
}

#endif
