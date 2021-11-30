#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>

#include "lib/stringInput.h"

#define TABLE_SIZE 10
#define KEY_SIZE 6
#define K 7 // Constant used for option 3
            // Must be prime larger than KEY_SIZE
#define INCR 7 // Constant used for double hashing
               // Must be prime smaller than TABLE_SIZE

typedef struct {
    char name[KEY_SIZE];
    int number;
    char status; // a = open, b = closed, c = deleted
} PERSON;

typedef struct {
    PERSON person[TABLE_SIZE];
} HASH;

HASH initialize() {
    HASH temp;
    for (int i = 0; i < TABLE_SIZE; i++) {
        temp.person[i].number = 0;
        strcpy(temp.person[i].name, "");
        temp.person[i].status = 'a';
    }
    return temp;
}

int stringToKey_option3(char chrKey[]) {
    int length = strlen(chrKey);
    printf("length: %d\n", length);
    int count = 0;

    for (int i = 0; i < length; i++) 
        count = count + chrKey[length - i - 1] * pow(K, i);
    
    return count;
}

int truncate(int key) {
    return key % 10;
}

PERSON inputData() {
    PERSON temp;
    printf("Enter name of person: ");
    stringInput(temp.name, KEY_SIZE);
    printf("Enter number of person: ");
    scanf("%d", &temp.number);
    emptyStdin();
    temp.status = 'b';
    return temp;
}

int doubleHashing(int index, int key) {
    int increment = 1 + (key % INCR);
    // index += (increment % TABLE_SIZE);
    index = (index + increment) % TABLE_SIZE;
    return index;
}

bool addToTable(HASH *hash, PERSON p, int index, int key) {
    int index_initial = index;
    bool found = false;

    while (!found) {
        if (hash->person[index].status == 'a' || hash->person[index].status == 'c') {
            hash->person[index] = p;
            printf("Added at [%d]\n", index);
            found = true;
        }
        else {
            index = doubleHashing(index, key);
            if (index == index_initial) {
                return false;
            }
        }
    }
    return found;
}

bool searchPerson(HASH hash, PERSON *p, int *index, int key, char chrKey[]) {
    int index_initial = *index;
    int nameComparison;
    bool found = false;

    while (!found) {
        nameComparison = strcmp(hash.person[*index].name, chrKey);
        if (nameComparison == 0) {
            *p = hash.person[*index];
            found = true;
        }
        else {
            *index = doubleHashing(*index, key);
            printf("Index: %d\n", *index);
            if (*index == index_initial)
                return false;
        }
    }
    return found;
}

bool deletePerson(HASH *hash, int index) {
    strcpy(hash->person[index].name, "");
    hash->person[index].number = 0;
    hash->person[index].status = 'c';
    return true;
}

int main()
{
    // char input[KEY_SIZE];
    // printf("Enter a string: ");
    // stringInput(input, KEY_SIZE);
    // printf("You input: %s\n", input);
    // int key = stringToKey_option3(input);
    // printf("Count: %d\n", key);
    // printf("\n\n");
    // HASH test = initialize();
    // test.person[0] = inputData();
    // printf("Person Name: %s\n", test.person[0].name);
    // printf("Person Number: %d\n", test.person[0].number);

    HASH test = initialize();
    PERSON personTest = inputData();
    int key = stringToKey_option3(personTest.name);    
    int index = truncate(key);
    addToTable(&test, personTest, index, key);

    personTest = inputData();
    key = stringToKey_option3(personTest.name);
    index = truncate(key);
    addToTable(&test, personTest, index, key);

    char searchKey[KEY_SIZE];
    printf("Input search key: ");
    stringInput(searchKey, KEY_SIZE);
    key = stringToKey_option3(searchKey);
    index = truncate(key);
    if (searchPerson(test, &personTest, &index, key, searchKey)) {
        printf("Person Number: %d\n", personTest.number);
        printf("Person Name: %s\n", personTest.name);
        deletePerson(&test, index);
        printf("%d deleted.\n", index);
    }
    else
        printf("Error. Person not found.\n");

    printf("Input search key: ");
    stringInput(searchKey, KEY_SIZE);
    key = stringToKey_option3(searchKey);
    index = truncate(key);
    if (searchPerson(test, &personTest, &index, key, searchKey)) {
        printf("Person Number: %d\n", personTest.number);
        printf("Person Name: %s\n", personTest.name);
    }
    else
        printf("Error. Person not found.\n");

    return 0;
}