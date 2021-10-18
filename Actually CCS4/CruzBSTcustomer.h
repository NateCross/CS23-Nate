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
}

void insertCustomer(ndCust *root, CUSTOMER custToAdd) {
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

// TODO: DELETE ME
void displayAllCustomers(ndCust tree) {
    if (tree != NULL) {
        displayAllCustomers(tree->left);

        printf("Customer Number: %s\n", tree->cust.number);
        printf("Customer Name: %s\n\n", tree->cust.name);

        displayAllCustomers(tree->right);
    }
}

#endif