#ifndef ITEM_H
#define ITEMS_H

#define ITEM_NUMBER 4
#define ITEM_NAME 30

typedef struct {
    int quantity;
    float price;
    char number[ITEM_NUMBER];
    char name[ITEM_NAME];
} ITEM;

typedef struct node_item *ndItem;
struct node_item {
    ITEM item;
    ndItem left;
    ndItem right;
} TREE_ITEM;

bool createItem(ITEM *temp) {
    printf("Enter item number: ");
    gets(temp->number);
    fflush(stdin);
    if (strlen(temp->number) >= ITEM_NUMBER) {
        printf("Error: Too many characters in number.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }

    printf("Enter item name: ");
    gets(temp->name);
    fflush(stdin);
    if (strlen(temp->name) >= ITEM_NAME) {
        printf("Error: Too many characters in name.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }

    printf("Enter item quantity: ");
    scanf("%d", &temp->quantity);
    fflush(stdin);

    printf("Enter item price: ");
    scanf("%f", &temp->price);
    fflush(stdin);

    return true;
}

void insertItem(ndItem *root, ITEM itemToAdd) {
    ndItem temp = malloc(sizeof(TREE_ITEM));
    temp->item = itemToAdd;
    temp->left = NULL;
    temp->right = NULL;

    ndItem ptr = *root, ptr1;
    int comparison;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ptr1 = ptr;
            comparison = numberComparison(temp->item.number, ptr->item.number);
            if (comparison < 0) // Less than
                ptr = ptr->left;
            else if (comparison > 0) // Greater than
                ptr = ptr->right;
            else { // Equal
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
    
    printf("Item successfully added.\n");
    printf("Press any key to return.\n");
    getch();
    return;
}

void displaySingleItem(ndItem node) {
    printf("Item Number: %s\n", node->item.number);
    printf("Quantity: %d\n", node->item.quantity);
    printf("Price: %.2f\n", node->item.price);
    printf("Name: %s\n", node->item.name);
}

// Prints all items in the tree,
// in item number order from least to greatest.
// It is formatted to resemble a table, with enough space
// to allow for larger values.
void displayAllItems(ndItem tree) {
    if (tree != NULL) {
        displayAllItems(tree->left);
        
        printf("%-6s", tree->item.number);
        printf("\t");
        printf("%-8d", tree->item.quantity);
        printf("\t");
        printf("%-10.2f", tree->item.price);
        printf("\t");
        printf("%-s", tree->item.name);
        printf("\n");

        displayAllItems(tree->right);
    }
    return;
}

// This function does some preliminary formatting
// before calling the recursive print function.
void initializeDisplayAllItems(ndItem tree) {
    system("cls");

    if (tree == NULL) {
        printf("Error: No items in list.\n");
        printf("Press any key to return.\n");
        getch();
        return;
    }

    printf("Item Display\n\n");

    printf("%-6s", "No.");
    printf("\t");
    printf("%-8s", "Qty.");
    printf("\t");
    printf("%-10s", "Price");
    printf("\t");
    printf("%-s", "Name");

    printf("\n\n");

    displayAllItems(tree);

    printf("\n\nPress any key to return.\n");
    getch();

    return;
}

bool inputSearchKey(char *search) {
    printf("Input entry number: ");
    gets(search);
    fflush(stdin);
    if (strlen(search) >= ITEM_NUMBER) {
        printf("Error: Too many characters in number.\n");
        printf("Press any key to return.\n");
        getch();
        return false;
    }
    return true;
}

bool searchDeleteItem(ndItem *ptr, ndItem *ptr1, char *key) {
    int comparison;
    while (*ptr != NULL) {
        comparison = numberComparison(key, (*ptr)->item.number);
        if (comparison == 0)
            return true;
        *ptr1 = *ptr;
        if (comparison < 0)
            *ptr = (*ptr)->left;
        else if (comparison > 0)
            *ptr = (*ptr)->right;
    }
    return false;
}

bool checkDeletion(ndItem node) {
    char choice;

    displaySingleItem(node);
    printf("\nDo you wish to continue deletion?\n");
    printf("1] Yes\n");
    printf("2] No\n");
    do {
        scanf("%c", &choice);
        fflush(stdin);
        if (choice == '1')
            return true;
        else if (choice == '2')
            return false;
        else
            printf("Error: Incorrect input. Please try again.\n");
    } while (choice != '1' || choice != '2');
}

bool deleteItemLeaf(ndItem *ptr, ndItem *ptr1, ndItem *root) {
    if (*ptr != *root) {
        if ((*ptr1)->left == *ptr)
            (*ptr1)->left = NULL;
        else
            (*ptr1)->right = NULL;
    }
    else
        *root = NULL;

    free (*ptr);

    return true;
}

bool deleteItemOneChild(ndItem *ptr, ndItem *ptr1, ndItem *root) {
    if (*ptr != *root) {
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
    else {
        if ((*root)->left != NULL)
            *root = (*root)->left;
        else
            *root = (*root)->right;
    }
    free (*ptr);
    return true;
}

bool deleteItemTwoChildren(ndItem *ptr, ndItem *ptr1) {
    ndItem ptr2 = NULL;
    *ptr1 = (*ptr)->right;
    while ((*ptr1)->left != NULL) { 
        ptr2 = *ptr1;
        *ptr1 = (*ptr1)->left;
    } // Traversal to find in order successor

    (*ptr)->item = (*ptr1)->item;

    if (ptr2 != NULL) {
        if ((*ptr1)->right != NULL)
            ptr2->left = (*ptr1)->right;
        else
            ptr2->left = NULL;
    }
    else {
        if ((*ptr1)->right != NULL)
            (*ptr)->right = (*ptr1)->right;
        else
            (*ptr)->right = NULL;
    }
    free(*ptr1);
    return true;
}

void deleteItemProcedure(ndItem *root, char *key) {
    system("cls");
    if (*root == NULL) {
        printf("Error: No items in list.\n");
        printf("Press any key to return.\n");
        getch();
        return;
    }

    ndItem ptr = *root, ptr1;
    bool isDeleted;

    if (searchDeleteItem(&ptr, &ptr1, key)) {
        if (checkDeletion(ptr)) {
            if (ptr->left == NULL && ptr->right == NULL)
                isDeleted = deleteItemLeaf(&ptr, &ptr1, root);
            else if (ptr->left != NULL && ptr->right != NULL)
                isDeleted = deleteItemTwoChildren(&ptr, &ptr1);
            else
                isDeleted = deleteItemOneChild(&ptr, &ptr1, root);
            
            if (isDeleted)
                printf("Successfully deleted item.\n");
            else
                printf("Failed to delete item.\n");
        }
        else
            return;
    }
    else
        printf("Error: Item not found.\n");
        
    printf("Press any key to return.\n");
    getch();
    return;
}

#endif