bool searchTree(nd *root, int key) {
    if (*root == NULL)
        return;
    
    nd ptr = *root;
    while (ptr != key) {
        if (key < ptr->number)
            ptr = ptr->left;
        else
            ptr = ptr->right;

        if (pt)
    }

    if (ptr->number == key)
        return true;
    else
        return false;
}

bool searchNode(nd *ptr, nd *ptr1, int key) {
    if (*ptr == NULL)
        return false;

    while (*ptr != NULL) {
        *ptr1 = *ptr;
        if (key < (*ptr)->number)
            *ptr = (*ptr)->left;
        else if (key == (*ptr)->number)
            return true;
        else
            *ptr = (*ptr)->right;
    }

    return false;
}

bool searchNode(nd *ptr, nd *ptr1, int key) {   // Cleanest searchNode
    while (*ptr != NULL) {
        if ((*ptr)->number == key)
            return true;
        *ptr1 = *ptr;
        if (key < (*ptr)->number)
            *ptr = (*ptr)->left;
        else
            *ptr = (*ptr)->right;
    }
    return false;
}

void addNode(nd *root) {    // TODO
    nd ptr = *root, ptr1;
    
    if (*root == NULL)
        
    }
}
/*
Steps to add node:
1. Pass *root
2. Create a new node, with some values in it
3. nd ptr = *root, ptr1;
4. if root != NULL go to a, else b
a. 
void addNode(nd *root)
nd temp = malloc(sizeof(NODE));
temp->number = some number
temp->left = NULL;
temp->right = NULL;

nd ptr = *root, ptr1;

if (*root != NULL) {
    while (ptr != NULL) {
        ptr1 = ptr;
        if (key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (key < ptr1->key)
        ptr1->left = temp;
    else
        ptr1->right = temp;
}
else
    *root = temp;
*/

void addNode (nd *root) {
    struct tempData = createStruct(some number);
    nd temp = malloc(sizeof(NODE));
    temp->data = tempData;
    temp->left = NULL;
    temp->right = NULL;

    nd ptr = *root, ptr1;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ptr1 = ptr;
            if (temp->data.number < ptr->data.number)
                ptr = (*ptr)->left;
            else
                ptr = (*ptr)->right;
        }
        if (temp->data.number < ptr1->data.number)
            ptr1->left = temp;
        else
            ptr1->right = temp;
    }
    else
        *root = temp;
    return;
}

nd addNode(nd *root) {
    if (*root == NULL)
        return createNode(root)
}

void deleteProcedure(nd *root) {    // TODO


}