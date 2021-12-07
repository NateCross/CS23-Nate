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
    nd    searchNode = NULL;
    TABLE hashTable[TABLE_SIZE];

    initTable(hashTable);

    do {
        searchNode = NULL;
        system("cls");

        printf("\n\n\tLibrary Management System\n\n"); 
        printf("1. Add a new book record\n");
        printf("2. Edit book information\n");
        printf("3. View all the books\n");
        printf("4. View a specific book\n");
        printf("5. Delete a book\n");
        printf("6. Borrow a book\n");
        printf("7. Return a book\n");
        printf("0. Exit program\n");

        // Getting the char input this way prevents a buffer overflow
        // compared to the relatively less safe "scanf"
        scanf_s("%c", &choice, 1);
        flushStdin();

        switch (choice) {
            case '1':
                book = inputBook();
                printf("Book Number: %s\n", book.bkNumber);
                printf("Book Title: %s\n", book.bkTitle);
                printf("Book Author: %s\n", book.bkAuthor);
                printf("Book Publisher: %s\n", book.bkPublisher);
                printf("Book Status: %s\n", book.bkStatus);
                printf("Book Copyright: %d\n", book.bkCopyright);
                _getch();

                key = convertStringOption2(book.bkNumber); 
                if (!key)
                    break;

                index = hashTruncation(key);
                printf("Inserting at index %d...\n", index);

                if (insertData(&hashTable[index], book))
                    printf("Successfully inserted!\n");
                else
                    printf("Insertion unsuccessful.\n");
               _getch();
                break;
            case '2':
                do {
                    searchNode = searchProcedure(hashTable, &index);
                    if (searchNode != NULL) {
                        displayBook(searchNode->book);
                        printf("\n\n");
                        editBook(&searchNode->book);
                        break;
                    }
                    printf("Do you wish to try again?\n");
                    printf("Enter 'n' to cancel, or enter anything else to try again: ");
                    scanf_s("%c", &prompt, 1);
                    flushStdin();
                } while (toupper(prompt) != 'N');

                break;
            case '3':
                viewAllBooks(hashTable);
                break;
            case '4':
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                printf("\n\n");
                displayBook(searchNode->book);
                _getch();
                break;
            case '5':
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                printf("\n\n");
                displayBook(searchNode->book);

                // The deletion prompt is placed here
                // so the source file is more plug and play
                // and so it does not need to load
                // unnecessary data
                printf("Do you wish to delete? Enter 'y' to confirm: ");
                scanf_s("%c", &prompt, 1);
                flushStdin();

                if (toupper(prompt) == 'Y') {
                    deleteBook(&hashTable[index], &searchNode);
                    printf("Book successfully deleted.\n");
                }
                else
                    printf("Book not deleted.\n");
                printf("Press any key to continue.\n");
                _getch();
                break;
            case '6':
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                borrowBook(&searchNode->book);
                break;
            case '7':
                searchNode = searchProcedure(hashTable, &index);
                if (searchNode == NULL)
                    break;
                returnBook(&searchNode->book);
                break;
            case '0':
                break;
            default:
                printError(E_INVALID_CHOICE);
                break;
        }
    } while (choice != '0');

    printf("Exiting program...\n");
    printf("Press any key to end.\n");
    _getch();    // _getch() is used instead of getch() to be ISO conformant
    return 0;
}
