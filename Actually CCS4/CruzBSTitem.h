#ifndef ITEM_H
#define ITEMS_H

typedef struct {
    int quantity;
    float price;
    char number[4];
    char name[30];
} ITEM;

typedef struct node_item *ndItem;
struct node_item {
    ITEM item;
    ndItem left;
    ndItem right;
} TREE_ITEM;

ITEM createItem() {
    ITEM temp;

    printf("Enter item number: ");
    gets(temp.number);
    fflush(stdin);
    printf("Enter item name: ");
    gets(temp.name);
    fflush(stdin);
    printf("Enter item quantity: ");
    scanf("%d", &temp.quantity);
    fflush(stdin);
    printf("Enter item price: ");
    scanf("%f", &temp.price);
    fflush(stdin);

    return temp;
}

void insertItem(ndItem *root, ITEM itemToAdd) {
    ndItem temp = malloc(sizeof(TREE_ITEM));
    temp->item = itemToAdd;
    temp->left = NULL;
    temp->right = NULL;
    // printf("Item number: %s", temp->item.number);

    ndItem ptr = *root, ptr1;
    int comparison;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ptr1 = ptr;
            comparison = strcmp(temp->item.number, ptr->item.number);
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
        if (comparison < 0) // Less than
                ptr1->left = temp;
        else if (comparison > 0) // Greater than
                ptr1->right = temp;
    }
    else
        *root = temp;
    
    printf("Node successfully added.\n");
    printf("Press any key to return.\n");
    getch();
    return;
}

#endif