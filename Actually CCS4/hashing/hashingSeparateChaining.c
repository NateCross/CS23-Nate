#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/stringInput.h"

#define TABLE_SIZE 10
#define KEY_SIZE 5      // This is S in Sir's
#define K 7 // Used in option 3 equation
            // It must be a prime larger than KEY_SIZE

// struct Node {
    // char data[KEY_SIZE];
    // struct Node *next;
// };

struct Node {
    char data[KEY_SIZE];
    struct Node *left;
    struct Node *right;
};

// struct Table {
    // char status; // y - yes, n - no, d - deleted
    // struct Node *chain;
// };

struct Table {
    char status;
    struct Node *chain;
};

void initializeTable(struct Table tab[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tab[i].status = 'n';
        tab[i].chain = NULL;
    }
    return;
}

struct Node * inputData() {
    struct Node *temp = malloc(sizeof(struct Node));
    printf("Input data: \n");
    /* emptyStdin(); */
    // fgets(temp->data, KEY_SIZE, stdin);
    // temp->data[strcspn(temp->data, "\n")] = 0;
    stringInput(temp->data, KEY_SIZE);
    // temp->next = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int convertString_Option3(char chrKey[]) {
    int length = strlen(chrKey);
    int key = 0;
    for (int i = 0; i < length; i++)
        key += (chrKey[length - i - 1] * pow(K, i));
    
    printf("count: %d\n", key);
    return key;
}

int hash_Truncation(int key) {
    return key % 10;
}

bool insertChain(struct Table tab[], struct Node *nd) {
    bool inserted = false;
    int index, key;

    key = convertString_Option3(nd->data);
    index = hash_Truncation(key);

    if (tab[index].chain != NULL) {
        struct Node *chain = tab[index].chain;
        struct Node *chain2 = tab[index].chain;
        printf("hi\n");
        // if (chain->next == NULL) {
            // printf("my value: %s\n", chain->data);
        // }
        
        // while (chain->next != NULL)
            // chain = chain->next;
        // printf("hello\n");
        // chain->next = nd;

        while (chain2 != NULL) {
            chain = chain2;
            printf("strcmp: %d\n", strcmp(chain2->data, nd->data));
            if (strcmp(chain2->data, nd->data) < 0) {
                chain2 = chain2->left;
                printf("I went left;");
            }
            else if (strcmp(chain2->data, nd->data) > 0)
                chain2 = chain2->right;
            printf("hello\n");
        }
        printf("yes\n");
        // if (strcmp(chain->data, chain2->data) > 0)
            // chain->left = nd;
        // else if (strcmp(chain->data, chain2->data) < 0)
            // chain->right = nd;
        if (chain2 == NULL)
            printf("chain2 is null\n");
        if (strcmp(chain->data, nd->data) < 0) {
            chain->left = nd;
            printf("I added left\n");
        }
        else if (strcmp(chain->data, nd->data) > 0)
            chain->right = nd;
        inserted = true;
    }
    else {
        tab[index].chain = nd;
        inserted = true;
    }
    printf("end of insertion\n");
    return inserted;
}

/* bool searchDelete() { */
    
/* } */

int main() {
    struct Table test[TABLE_SIZE];
    initializeTable(test);
    // test[0].chain = inputData();
    // printf("chain: %s\n", test[0].chain->data);
    // char testStr[KEY_SIZE];
    // printf("Input something: ");
    // stringInput(testStr, KEY_SIZE);
    // printf("You input: %s", testStr);
    // int key = convertString_Option3(test[0].chain->data);
    
    struct Node *toInsert = inputData();
    insertChain(test, toInsert);

    struct Node *toInsert1 = inputData();
    insertChain(test, toInsert1);

    toInsert = inputData();
    insertChain(test, toInsert);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (test[i].chain != NULL) {
            printf("[%d]: %s\n", i, test[i].chain->data);
            // if (test[i].chain->left != NULL) 
                // printf("[%d]: %s\n", i, test[i].chain->left->data);
            if (test[i].chain->right != NULL) {
                printf("[%d]: %s\n", i, test[i].chain->right->data);
                printf("[%d]: %s\n", i, test[i].chain->right->right->data);
                printf("[%d]: %s\n", i, test[i].chain->right->left->data);
            } 

            // while(test[i].chain->next != NULL) {
                // test[i].chain = test[i].chain->next;
                // printf("\t[%d]: %s\n", i, test[i].chain->data);
            // }

            // while(test[i].chain->left != NULL) {
                // test[i].chain = test[i].chain->next;
                // printf("\t[%d]: %s\n", i, test[i].chain->data);
            // }

            // while(test[i].chain->next != NULL) {
                // test[i].chain = test[i].chain->next;
                // printf("\t[%d]: %s\n", i, test[i].chain->data);
            // }
        } 
    }

    _getch();

    return 0;
}

