#include <string.h>
#include <stdio.h>
#include "inputHelper.h"

void flushStdin() {
    for (int c = getchar(); c != '\n' && c != EOF; c = getchar()) {}
}
// Using the other flush forces you to press twice
// if the number of characters is not equal to the max
// if using the fgets to handle strings;
// fseek, on the other hand, works fine with this
// with the caveat that it only functions on Windows
void flushString() {
    fseek(stdin, 0, SEEK_END);
}

// This function takes in a string input, snips the \n,
// and flushes the input in a cleaner way than fflush(stdin)
void inputString(char input[], int size) {
    flushString();

    // fgets is used because it safer against buffer overflows
    fgets(input, size, stdin);

    // Removes the \n character; if the \n is left in,
    // the values when converting string to int are incorrect
    input[strcspn(input, "\n")] = 0;
}

int inputInt() {
    char buffer[256];
    int num;

    flushString();
    fgets(buffer, 256, stdin);
    sscanf_s(buffer, "%d", &num);

    return num;
}
