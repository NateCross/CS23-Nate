// Library Management System
//
// This program aims to facilitate management of the books in a library.
// It is capable of storing and retrieving information of a certain book,
// using a hash function to make placing and locating it faster.
// It is also capable of viewing the information of a book, as well as
// deleting it and marking a book as "borrowed" or "returned."
//
// For collision resolution, this program makes use of separate chaining
// which appends a doubly-linked list to each index of the hash table.
// New books mapped to the same index will be added at the beginning 
// of each index, pushing others further down the list.
// This allows for near-instantaneous insertion time no matter how much
// data is being handled.
// Additionally, this program is written to conform to C99 standards.
// 
// Written by:     Nathan Angelo B. Cruz
// Date started:   12/06/2021
// Date completed: 12/07/2021

#include <stdio.h>
#include <conio.h>       // Required for _getch()
#include <stdlib.h>      // Required for system("cls")
#include <stdbool.h>
#include <ctype.h>       // Required for toupper()

#include "inputHelper.h"
#include "hashTable.h"

int main() { 
    int   key;
    int   index;
    char  choice;
    char  prompt;
    BOOK  book;
    nd    searchNode;
    TABLE hashTable[TABLE_SIZE];

    initTable(hashTable);

    do {
        system("cls");

        printf("\n\n\tLibrary Management System\n\n"); 
        printf("\t1. Add a new book record\n");
        printf("\t2. Edit book information\n");
        printf("\t3. View all the books\n");
        printf("\t4. View a specific book\n");
        printf("\t5. Delete a book\n");
        printf("\t6. Borrow a book\n");
        printf("\t7. Return a book\n");
        printf("\t0. Exit program\n");
        printf("\t");

        // Safer version of scanf
        scanf_s("%c", &choice, 1);
        flushStdin();

        switch (choice) {
            case '1':
                system("cls");
                book = inputBook();
                
                key = convertStringOption2(book.bkNumber); 
                if (!key)
                    break;

                index = hashTruncation(key);
                printf("\n\n");
                printf("\tInserting at index %d...\n", index);

                if (insertData(&hashTable[index], book))
                    printf("\tSuccessfully inserted!\n");
                else
                    printf("\tInsertion unsuccessful.\n");
               _getch();
                break;
            case '2':
                do {
                    system("cls");
                    searchNode = searchProcedure(hashTable, &index);
                    printf("\n\n");
                    if (searchNode != NULL) {
                        displayBook(searchNode->book);
                        printf("\n");
                        editBook(&searchNode->book);
                        break;
                    }
                    printf("\tDo you wish to try again?\n");
                    printf("\tEnter 'n' to cancel, or enter anything else to try again: ");
                    scanf_s("%c", &prompt, 1);
                    flushStdin();
                } while (toupper(prompt) != 'N');

                break;
            case '3':
                displayAllBooks(hashTable);
                break;
            case '4':
                system("cls");
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                printf("\n\n");
                displayBook(searchNode->book);
                _getch();
                break;
            case '5':
                system("cls");
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                printf("\n\n");
                deleteBook(&hashTable[index], &searchNode);
                printf("\tPress any key to continue.\n");
                _getch();
                break;
            case '6':
                system("cls");
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                printf("\n\n");
                borrowBook(&searchNode->book);
                break;
            case '7':
                system("cls");
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                printf("\n\n");
                returnBook(&searchNode->book);
                break;
            case '0':
                system("cls");
                break;
            default:
                printError(E_INVALID_CHOICE);
                break;
        }
    } while (choice != '0');

    printf("\tExiting program...\n");
    printf("\tPress any key to end.\n");
    _getch();    // _getch() is used instead of getch() to be ISO conformant
    return 0;
}
