#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TABLE_SIZE_MA 101
#define TABLE_SIZE_TRUNCATION 999

// For TABLE_SIZE, powers of 2 must be avoided;
// It has a greater chance of colliding
int modular_arithmetic(int key) {
    return key % TABLE_SIZE_MA;
}

// Mod 1000 returns the last 3 digits of the key
// Problem: may not have even distribution
int truncation(int key) {
    return key % 1000;    
}

// Calibrated for 8 digits
// Folding is useful for large keys
int folding_eight_digits(int key) {
    int keyTruncated = key % 10000;
    key = (key - keyTruncated) / 10000;
    return key + keyTruncated;
}

int folding_nine_digits(int key) {
    int count = 0;
    int key_subtractor = 0;

    // The steps to this process are clearly outlined 
    while (key > 0) {
        key_subtractor = key % 1000;
        count += key_subtractor;
        key -= key_subtractor;
        key /= 1000;
    }

    return count;
}

char radix_processNumber(int key, int base) {
    int num = key % base;
    if (num <= 9)
        return num + '0';
    else 
        return num - 10 + 'A';    // This is where 'A' starts
}

// const char * radix_conversion(int key) {
//     int base = 11;
//     int countSize = 0;
//     char *count[100] = {" "};
//     while (key) {
//         // *count[countSize] = radix_processNumber(key, base);
//         char processedNumber = radix_processNumber(key, base);
//         strcat(*count, &processedNumber);
//         countSize++;
//         key /= base;
//         printf("key: %d\n", key);
//         _getch();
//     }
//     _strrev(*count);
//     return *count;
// }

void radix_conversion(int key, int base, char count[]) {
    while (key) {
        char processedNumber = radix_processNumber(key, base);
        // printf("processedNumber: %c\n", processedNumber);
        strncat(count, &processedNumber, 1);
        // countSize++;
        key /= base;
        // printf("key: %d\n", key);
        // _getch();
    }
    _strrev(count);
    return;
}

int mid_square_five_digits(int key) {
    key *= key; // Squaring the key
    return ((key - (key % 100)) / 100) % 10000;
}

int main() {
    printf("%d\n", folding_nine_digits(259367157));
    char test[100] = {};
    radix_conversion(87903, 11, test);
    printf("%s\n", test);
    printf("%d\n", mid_square_five_digits(4765));

    _getch();
    return 0;
}
