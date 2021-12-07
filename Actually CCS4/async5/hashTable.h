#ifndef __HASH_TABLE_
#define __HASH_TABLE_

#include <stdbool.h>

#define BKNUMBER_LENGTH 5
#define BKSTRING_LENGTH 256     // For the rest of the strings
#define STRING_CONVERSION_DIGITS 3      // Number of digits taken at the end of the string
#define TABLE_SIZE 100

// This enum defines the types of errors that occur.
// The display message for each error is located in the hashTable.c file
// under the Error_str array
typedef enum {
    E_BOOK_NUMBER_INCORRECT_LENGTH = 0,
    E_BOOK_NOT_FOUND,
    E_BOOK_ALREADY_BORROWED,
    E_BOOK_ALREADY_AVAILABLE,
    E_INVALID_CHOICE,
    E_BOOK_NUMBER_ALREADY_EXISTS,
} HASH_TABLE_ERROR;

typedef struct {
    int  bkCopyright;
    char bkNumber[BKNUMBER_LENGTH];     // Used as key for hashing
    char bkTitle[BKSTRING_LENGTH];
    char bkAuthor[BKSTRING_LENGTH];
    char bkPublisher[BKSTRING_LENGTH];
    char bkStatus[BKSTRING_LENGTH];
} BOOK;

typedef struct NODE *nd;
struct NODE {
    BOOK book;
    nd   prev;
    nd   next;
}; 

typedef struct {
    nd hash;
} TABLE;

void printError(HASH_TABLE_ERROR);
void initTable(TABLE []);
BOOK inputBook();
int  convertStringOption2(char []);
int  hashTruncation(int);
bool insertData(TABLE *, BOOK);
void inputSearchKey(char []);
nd   searchBook(TABLE, char []);
void displayBook(BOOK);
void deleteBook(TABLE *, nd *);
void displayAllBooks(TABLE []);
nd   searchProcedure(TABLE [], int *);
void editBook(BOOK *);
void borrowBook(BOOK *);
void returnBook(BOOK *);

#endif
