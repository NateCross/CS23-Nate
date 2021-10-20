#ifndef SHARE_H
#define SHARED_H

// Compares numbers in strings for BST operations
// to emulate normal BST comparisons with integers;
// fixes the bug where 11 < 2, because strcmp
// only checks character by character
int numberComparison(char *num1, char *num2) {
    if (strlen(num1) > strlen(num2))
        return 1;
    else if (strlen(num1) < strlen(num2))
        return -1;
    else
        return strcmp(num1, num2);
}

void inputSearchKey(char *search) {
    printf("\tInput entry number: ");
    gets(search);
    fflush(stdin);
    return;
}

#endif