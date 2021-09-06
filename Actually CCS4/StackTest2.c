#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 50

//TODO: Postfix operation

typedef struct NODE *NODE;
struct NODE { //The thingy here must be the same as the struct name, the first thingy, declared above.
    int num;
    NODE next; //Already a pointer so no need to put pointer again
} stackNode; //I guess this is a name for my reference?

/* IDK how to use this but here it stays for this code is correct
NODE createStack (void) {
    NODE temp = NULL;
    return temp;
}
*/

void push (NODE *tos, int data) {
    NODE temp = malloc(sizeof(NODE));
    temp -> num = data;
    temp -> next = *tos;
    *tos = temp;
    return;
}

int pop (NODE *tos) {
    int data = (*tos) -> num;
    *tos = (*tos) -> next;
    return data;
}

int peek (NODE tos) {
    return tos -> num;
}

int isEmpty (NODE tos) { // I'm not actually using this but whatever, maybe I'll need it sooner or later
    if (tos != NULL)
        return 1;
    else
        return 0;
}

int main() {
    int n1, n2, constant, tempNum = 0;
    NODE top = malloc(sizeof(NODE)); //No need to typecast but ig we can if we need to
    char equation[SIZE];
    printf("Enter an equation: ");
    gets(equation);

    for (int i = 0; i <= strlen(equation) - 1; i++) { // Possible todo: Clean this up and make it a function
        if (equation [i] != ' ') {

            switch (equation[i]) { // This is to check which operation the character is, or if it is a number.
                case '+':
                    n2 = pop(&top);
                    n1 = pop(&top);
                    push(&top, n1 + n2);
                    i++; // The i++ is to skip a space; it will break if there are more than two numbers without this
                    break;
                case '-':
                    n2 = pop(&top); // n2 is here first because of sub and div
                    n1 = pop(&top);
                    push(&top, n1 - n2);
                    i++;
                    break;
                case '*':
                    n2 = pop(&top);
                    n1 = pop(&top);
                    push(&top, n1 * n2);
                    i++;
                    break;
                case '/':
                    n2 = pop(&top);
                    n1 = pop(&top);
                    push(&top, n1 / n2);
                    i++;
                    break;
                default:
                    tempNum = tempNum * 10 + equation[i] - 48; // A rolling count to parse multi-digit integers. It's -48 because 0 is character 48.
                    break;
            }
            //printf("%d - TOS\n", top -> num); //This is to check the top of stack
        }
        else if (equation[i] == ' ') {
            push(&top, tempNum);
            tempNum = 0;
        }
    }

    int testAgain = peek(top);
    printf("\nFinal Answer: %d", testAgain);

    return 0;
}
