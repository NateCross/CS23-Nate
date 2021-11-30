#include <stdio.h>
#include "stringInput.h"

int main() {
    char str[5];
    char str2[2];
    printf("Enter a string: ");
    stringInput(str, 5);
    printf("\n\nYou wrote: %s\n", str);
    printf("And another one: ");
    stringInput(str2, 2);
    printf("\n\nYou wrote: %s\n", str2);


    return 0;
}
