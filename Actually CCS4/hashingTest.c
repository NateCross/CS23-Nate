// TODO: Do the functions listed in notes
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "lib/stringInput.h"

#define KEY_SIZE 8
#define HASH_SIZE 10
#define NAME_SIZE 20
#define K 7             // K is used in the option 3 equation
#define INCR 7          // Used for double hashing
#define FLUSH while ( getchar() != '\n' )

typedef struct {
    char personId[KEY_SIZE];
    char personName[NAME_SIZE];
} PERSON;

typedef struct {
    PERSON person;
    char status;    // 'e' = empty, 'o' = occupied, 'd' = deleted   
} TABLE;

void initTable(TABLE T[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        memset(T[i].person.personId, '\0', KEY_SIZE);
        memset(T[i].person.personName, '\0', NAME_SIZE);
        T[i].status = 'e';
    }
    return;
}

int convertStringOption3(char chrKey[]) {
    int length = strlen(chrKey);
    int key = 0;

    for (int i = 0; i < length; i++) {
        // This block handles if the char is already a number
        // Because according to the ppt., numbers are not supposed to be
        // converted using its ASCII values
        if (chrKey[length - i - 1] >= '0' && chrKey[length - i - 1] <= '9')
            key = key + chrKey[length - i - 1] - '0'; 
        else
            key = key + (chrKey[length - i - 1] * pow(K, i));
    }
    return key;
}

int hashTruncation(int key) {
    // int index;
    // index = key % 10;   // Extract the last digit (single digit index)
    // return index;
    //
    return (key % 10);
}

int linearProbing(int index) {
    return (index + 1) % HASH_SIZE;
}

int doubleHashing(int index, int key) {
    int increment;

    increment = 1 + (key % INCR);
    index = (index + increment) % HASH_SIZE;    // It's originally LH, not HASH_SIZE
    return index;
}

bool insertData(TABLE T[], PERSON per) {
    int index, key, P;
    // int P = -1 -- this doesn't work though the loop will work
    bool full = false;

    key = convertStringOption3(per.personId);
    printf("key: %d\n", key);
    index = hashTruncation(key);
    P = index;

    // The problem with while(true) for the block below is that it doesn't check
    // if the table is full; it will always be false if so
    //
    while(!full) {
        if (T[P].status == 'e' || T[P].status == 'd') {     // Step 2
            T[P].person = per;
            break;
        }
        else {
            P = doubleHashing(P, key);
            if (P == index)
                full = true;
        }   // if occupied, Step 3
    }
    printf("index: %d\n", P);
    _getch();
    return full;
}

PERSON inputData() {
    PERSON temp;
    printf("\tEnter ID: \n");
    fgets(temp.personId, KEY_SIZE, stdin);
    temp.personId[strcspn(temp.personId, "\n")] = 0;
    printf("\tEnter name:\n");
    fgets(temp.personName, NAME_SIZE, stdin);
    temp.personName[strcspn(temp.personName, "\n")] = 0;
    return temp;
}

void inputSearchKey(char chrKey[]) {
    printf("\tEnter search key: \n");
    // fgets(chrKey, KEY_SIZE - 1, stdin);
    // chrKey[strcspn(chrKey, "\n")] = 0;
    stringInput(chrKey, KEY_SIZE);
    // printf("strlen: %d\n", strlen(chrKey));
    // gets(chrKey);
    return;
}

void displayData(PERSON per) {
    printf("\tPerson ID: %s\n", per.personId);
    printf("\tPerson Name: %s\n", per.personName);
    return;
}

bool searchData(TABLE T[], int index, char chrKey[], int key, PERSON *per) {
    int initialIndex = index;
    bool found = false;

    while (!found) {
        printf("start of loop found\n");
        if (strcmp(T[index].person.personId, chrKey) == 0)
            found = true;
        else {
            index = doubleHashing(index, key);
            printf("index: %d\n", index);
            if (index == initialIndex)
                return false;
        }
        printf("end of loop found\n");
    }

    *per = T[index].person;
    displayData(*per);
    return found;
}

int main() {
    int choice, key, index;
    char chrKey[NAME_SIZE];
    PERSON per;
    bool found = false;
    TABLE T[HASH_SIZE];

    initTable(T);
    do {
        system("cls");
        printf("\t1] Add new data\n");
        printf("\t2] Search a data\n");
        printf("\t3] Delete a data\n");
        printf("\t4] Exit\n\n");
        // fgets(choice, 1, stdin);
        scanf_s("%d", &choice);
        FLUSH;
        // sscanf(stdin, "%d", &choice);

        switch (choice) {
            case 1:
                per = inputData();
                insertData(T, per);
                break;
            case 2:
                inputSearchKey(chrKey);
                key = convertStringOption3(chrKey);
                printf("key: %d\n", key);
                index = hashTruncation(key);
                printf("index: %d\n", index);
                found = searchData(T, index, chrKey, key, &per);
                if (found)
                    displayData(per);
                else
                    printf("\n\n\tError: Data not found...");
                _getch();
                break;
            default:
                break;
        }
    } while (choice != 4);
    _getch();
    return 0;
}

