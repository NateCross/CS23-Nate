#ifndef CUST_H
#define CUSTS_H

#define CUSTOMER_NUMBER 4
#define CUSTOMER_NAME 40

typedef struct {
    char number[CUSTOMER_NUMBER];
    char name[CUSTOMER_NAME];
} CUSTOMER;

typedef struct node_customer *ndCust;
struct node_customer {
    CUSTOMER cust;
    ndCust left;
    ndCust right;
} TREE_CUST;

bool createCustomer(CUSTOMER *temp) {
    printf("Enter customer number: ");
    gets(temp->number);
    fflush(stdin);
    if (strlen(temp->number) >= CUSTOMER_NUMBER) {
        printf("Error: Too many characters in number.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }

    printf("Enter customer name: ");
    gets(temp->name);
    fflush(stdin);
    if (strlen(temp->name) >= CUSTOMER_NAME) {
        printf("Error: Too many characters in name.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }
    return true;
}

void insertCustomer(ndCust *root) {
    CUSTOMER custToAdd;
    if (!createCustomer(&custToAdd))
        return;

    ndCust temp = malloc(sizeof(TREE_CUST));
    temp->cust = custToAdd;
    temp->left = NULL;
    temp->right = NULL;

    ndCust ptr = *root, ptr1;
    int comparison;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ptr1 = ptr;
            comparison = numberComparison(temp->cust.number, ptr->cust.number);
            
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

    printf("Customer successfully registered.\n");
    printf("Press any key to return.\n");
    getch();
    return;
}

#endif