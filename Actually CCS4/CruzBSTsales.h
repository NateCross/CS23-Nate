#ifndef SALE_H
#define SALES_H

#define SALES_NUMBER 7

typedef struct {
    int quantitySold;
    char itemNumber[ITEM_NUMBER];
    char custNumber[CUSTOMER_NUMBER];
    char saleNumber[SALES_NUMBER];
} SALES;

typedef struct node_sales *ndSale;
struct node_sales {
    SALES sale;
    ndSale left;
    ndSale right;
} TREE_SALE;

bool createSale(SALES *temp) {
    printf("Enter item number: ");
    gets(temp->itemNumber);
    fflush(stdin);
    if (strlen(temp->itemNumber) >= ITEM_NUMBER) {
        printf("Error: Too many characters in number.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }

    printf("Enter customer number: ");
    gets(temp->custNumber);
    fflush(stdin);
    if (strlen(temp->custNumber) >= CUSTOMER_NUMBER) {
        printf("Error: Too many characters in number.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }

    printf("Enter quantity of items to be sold: ");
    scanf("%d", &temp->quantitySold);
    fflush(stdin);

    strcpy(temp->saleNumber, temp->itemNumber);
    strcat(temp->saleNumber, temp->custNumber);
}

bool checkSaleValidity(SALES saleToCheck, ndItem *ptr, ndItem *ptr1) {
    if (!(searchDeleteItem(ptr, ptr1, saleToCheck.itemNumber))) {
        printf("Error: Item number does not exist.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }
    if ((*ptr)->item.quantity == 0) {
        printf("Error: Item is out of stock.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }
    if (saleToCheck.quantitySold < 0) {
        printf("Error: Quantity sold to customer is negative.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }
    return true;
}

void insertSale(ndSale *root, SALES saleToAdd, ndItem *itemList) {
    ndItem itemPtr = *itemList, itemPtr1;
    bool saleIsValid = checkSaleValidity(saleToAdd, &itemPtr, &itemPtr1);
    if(!saleIsValid)
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
            comparison = numberComparison(temp->sale.saleNumber, ptr->sale.saleNumber);
            if (comparison < 0)
                ptr = ptr->left;
            else if (comparison > 0)
                ptr = ptr->right;
            else {
                printf("Error: Number already exists.\n");
                printf("Press any key to return.\n");
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

    printf("Sale successfully added.\n");
    printf("Press any key to return.\n");
    getch();
    return;
}

// TODO: DELETE ME
void displayAllSales(ndSale tree) {
    if (tree != NULL) {
        displayAllSales(tree->left);

        printf("Sale Number: %s\n", tree->sale.saleNumber);
        printf("Quantity Sold: %d\n", tree->sale.quantitySold);
        printf("Item Number: %s\n", tree->sale.itemNumber);
        printf("Customer Number: %s\n\n", tree->sale.custNumber);

        displayAllSales(tree->right);
    }
}

#endif