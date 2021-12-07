#include "hashTable.h"
#include "inputHelper.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

// This matches the error enums to a corresponding string
// which is used in printError().
const char * const Error_str[] = {
    [E_BOOK_NUMBER_INCORRECT_LENGTH] = "Book number must be 4 digits.",
    [E_BOOK_NOT_FOUND] = "Book not found.",
    [E_BOOK_ALREADY_BORROWED] = "Book already borrowed.",
    [E_BOOK_ALREADY_AVAILABLE] = "Book already available.",
    [E_INVALID_CHOICE] = "Invalid choice.",
    [E_BOOK_NUMBER_ALREADY_EXISTS] = "Book number already exists.",
};

void printError(HASH_TABLE_ERROR err) {
    printf("\tERROR %d: %s\n", err, Error_str[err]);
    printf("\tPress any key to continue.\n");
    _getch();
    return;
}

void initTable(TABLE temp[]) {
    for (int i = 0; i < TABLE_SIZE; i++)
        temp[i].hash = NULL;

    return;
}

BOOK inputBook() {
    BOOK temp;
    
    printf("\n\n");
    printf("\tEnter 4-character book number: ");
    inputString(temp.bkNumber, BKNUMBER_LENGTH);
    printf("\tEnter book title: ");
    inputString(temp.bkTitle, BKSTRING_LENGTH);
    printf("\tEnter book author: ");
    inputString(temp.bkAuthor, BKSTRING_LENGTH);
    printf("\tEnter book publisher: ");
    inputString(temp.bkPublisher, BKSTRING_LENGTH);
    printf("\tEnter book copyright: ");
    temp.bkCopyright = inputInt();
    memcpy(temp.bkStatus, "Available", strlen("Available") + 1);

    return temp;
}

// Algorithm to obtain an int from a string
// From the last digit, it goes backwards a number of times
// equal to STRING_CONVERSION_DIGITS. Each time, 
// it converts the ASCII value of the digit expressed as a base 27 number
// into a base 10 number, then adds that to the rolling count.
int convertStringOption2(char input[]) {
    int inputLength = strlen(input);

    // Return guards
    if (inputLength != BKNUMBER_LENGTH - 1) {
        printError(E_BOOK_NUMBER_INCORRECT_LENGTH);
        return 0;
    }

    int count = 0;      // Initialized to 0 to avoid undefined behavior

    for (int i = inputLength - 1; i >= inputLength - STRING_CONVERSION_DIGITS; i--) 
        count += input[i] * pow(27, inputLength - i - 1);
    

    return count;
}

// The hash method.
// Returns the last two digits of the key.
int hashTruncation(int key) {
    return key % 100;
}

bool insertData(TABLE *hashTable, BOOK bk) {
    nd temp = malloc(sizeof(struct NODE));
    temp->book = bk;
    temp->next = NULL;
    temp->prev = NULL;

    if (hashTable->hash != NULL) {
        temp->next = hashTable->hash;
        hashTable->hash->prev = temp;
    }

    hashTable->hash = temp;

    return true;
}

void inputSearchKey(char searchKey[]) {
    printf("\n\n");
    printf("\tEnter book number to search: ");
    inputString(searchKey, BKNUMBER_LENGTH);
    flushString(); // Required to prevent having to press enter twice
    return;
}

nd searchBook(TABLE hashTable, char searchKey[]) {
    nd ptr = hashTable.hash;

    while (ptr != NULL) {
        if (strcmp(searchKey, ptr->book.bkNumber) == 0) {
            break;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printError(E_BOOK_NOT_FOUND);
    }

    return ptr;
}

void displayBook(BOOK bk) {
    printf("\tBook Number: %s\n", bk.bkNumber);
    printf("\tTitle: %s\n", bk.bkTitle);
    printf("\tAuthor: %s\n", bk.bkAuthor);
    printf("\tPublisher: %s\n", bk.bkPublisher);
    printf("\tStatus: %s\n", bk.bkStatus);
    printf("\tCopyright: %d\n", bk.bkCopyright);

    return;
}

// This program uses a doubly-linked list to facilitate
// deleting data. It makes it much simpler to do so
// by letting the previous node point to the next node,
// and letting the next node point to the previous, if it exists.
void deleteBook(TABLE *hashTable, nd *deleteNd) {
    char choice;

    displayBook((*deleteNd)->book);
    printf("\tDo you wish to delete?\n");
    printf("\tEnter 'y' to confirm and anything else to exit:\n");

    printf("\t");
    scanf_s("%c", &choice, 1);
    flushStdin();

    if (toupper(choice) != 'Y') {
        printf("\tBook not deleted.\n");
        return;
    }

    if (*deleteNd == hashTable->hash) 
        hashTable->hash = (*deleteNd)->next;
    else {
        (*deleteNd)->prev->next = (*deleteNd)->next;
        if ((*deleteNd)->next != NULL) 
            (*deleteNd)->next->prev = (*deleteNd)->prev;
    }
    free(*deleteNd);

    printf("\tBook successfully deleted.\n");
    
    return;
}

// If the formatting looks weird, increase the window size
void displayAllBooks(TABLE hashTable[]) {
    system("cls");
    nd ptr;

    printf("\n\n");
    printf("| %-5s | %-11s | %-30s | %-30s | %-30s | %-13s | %-15s |\n",
            "Index", "Book Number", "Title", 
            "Author", "Publisher", 
            "Status", "Copyright");
    for (int i = 0; i < TABLE_SIZE; i++) {
        ptr = hashTable[i].hash;
        while(ptr != NULL) {
            printf("| %-5d ", i);
            printf("| %-11s ", ptr->book.bkNumber);
            printf("| %-30s ", ptr->book.bkTitle);
            printf("| %-30s ", ptr->book.bkAuthor);
            printf("| %-30s ", ptr->book.bkPublisher);
            printf("| %-13s ", ptr->book.bkStatus);
            printf("| %-15d |", ptr->book.bkCopyright);
            // displayBook(ptr->book);
            ptr = ptr->next;
            printf("\t\n");
        }
    }
    _getch();

    return;
}

// This function calls all the necessary functions in correct order
// to perform the search operation on the hash table.
// Use this function whenever you searching is required,
// instead of the other functions separately.
// Note that index is passed here because it is still
// needed for the delete function.
nd searchProcedure(TABLE hashTable[], int *index) {
    char searchKey[BKNUMBER_LENGTH]; 

    inputSearchKey(searchKey);

    int key = convertStringOption2(searchKey);
    if (!key)
        return NULL;

    *index = hashTruncation(key);

    nd temp = searchBook(hashTable[*index], searchKey); 

    return temp;
}

// Allows the user to edit only the author and publisher;
// the other fields are fixed and may not be edited, as per
// project specifications
void editBook(BOOK *bk) {
    printf("\tEnter new author: ");
    inputString(bk->bkAuthor, BKSTRING_LENGTH);
    printf("\tEnter new publisher: ");
    inputString(bk->bkPublisher, BKSTRING_LENGTH);

    return;
}

void borrowBook(BOOK *bk) {
    if (strcmp(bk->bkStatus, "Not Available") == 0) {
        printError(E_BOOK_ALREADY_BORROWED);
        return;
    }
    memcpy(bk->bkStatus, "Not Available", strlen("Not Available") + 1);
    printf("\tBook successfully borrowed.\n");
    printf("\tPress any key to continue.\n");
    _getch();

    return;
}

void returnBook(BOOK *bk) {
    if (strcmp(bk->bkStatus, "Available") == 0) {
        printError(E_BOOK_ALREADY_AVAILABLE);
        return;
    }
    memcpy(bk->bkStatus, "Available", strlen("Available") + 1);
    printf("\tBook successfully returned.\n");
    printf("\tPress any key to continue.\n");
    _getch();

    return;

}
