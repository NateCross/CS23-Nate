#include "stringInput.h"
#include <string.h>
#include <stdio.h>

void stringInput(char input[], int size) {
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0;
    while((c = getchar()) != '\n' && c != EOF)
}
