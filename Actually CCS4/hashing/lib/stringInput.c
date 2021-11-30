#include "stringInput.h"
#include <string.h>
#include <stdio.h>
#define FLUSH while (getchar() != '\n')

void emptyStdin() {
    /* for (int c = getchar(); c != '\n' && c != EOF; c = getchar()) {} */
    /* FLUSH; */
    /* int c; */
    /* while ((c = getchar()) != '\n' && c != EOF) { } */
    fseek(stdin,0,SEEK_END);
}

// The input cleaning was taken from
// https://c-for-dummies.com/blog/?p=2631
void stringInput(char input[], int size) {
    /* int x = 0; */
    /* int c; */
    /* while ((c = getchar()) != '\n' && c != EOF); */

    emptyStdin();
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0;
    /* for(int x=0;x<=size;x++) */
        /* { */
            /* if( input[x] == '\n') */
            /* { */
                /* input[x] = '\0'; */
                /* break; */
            /* } */
        /* } */
    /* scanf("%*[^\n]%1*[\n]"); */
    /* while(*input) */
        /* { */
            /* if(*input == '\n') */
            /* { */
                /* *input = '\0'; */
                /* return; */
            /* } */
            /* x++; */
            /* if(x == size) */
            /* { */
                /* *input = '\0'; */
                /* return; */
            /* } */
            /* input++; */
        /* } */

    /* [> fflush(stdin); <] */

}
