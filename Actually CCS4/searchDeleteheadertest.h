// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <conio.h>

typedef struct {
    char studName[50];
    int studID;
} STUD;

typedef struct node *nd;
struct node {
    nd left, right;
    STUD student;
} NODE;