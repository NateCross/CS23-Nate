#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 50

int main() {
    char stringTest[SIZE], *endPtr;
    double num[SIZE];
    printf("Enter number here: ");
    gets(stringTest);
    endPtr = stringTest;

    num[0] = strtod(endPtr, &endPtr);
    endPtr++;
    printf("endPtr[0] = %c\n", *endPtr);
    endPtr[0] = ' ';
    printf("String Check: %s\n", endPtr);
    num[1] = strtod(endPtr, &endPtr);
    printf("String Check: %s\n", endPtr);
    num[2] = strtod(endPtr, &endPtr);
    printf("String Check: %s\n", endPtr);
    /*
    for (int i = 0; i < strlen(stringTest); i++) {
        if (stringTest[i] >= '0' && stringTest[i] <= '9') {
            num[i]

            if (stringTest[i] - 1 == '-')
                num1 *= -1;
        }
        stringTest;
    }
    */

    printf("Number: %f, %f, %f", num[0], num[1], num[2]);
}
