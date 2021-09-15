#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

// Nate Cruz 2021

typedef struct node *NODE;
struct node {
	char data;
	NODE next;
}STACK;

void createStack(NODE *tos) {
	*tos = NULL;
}

bool isEmpty(NODE tos) {
	bool empty = false;
	if (tos == NULL)
		empty = true;
	return empty;
}

void push(NODE *tos, char input) {
    NODE temp = malloc(sizeof(STACK));
	temp->data = input;
	temp->next = *tos;
	*tos = temp;
	return;
}

void pop(NODE *tos) {
	NODE temp = *tos;
	*tos = (*tos)->next;
	free(temp);
	return;
}

void inputExpression(char Expr[]) {
    fflush(stdin);
	printf("Input an expression with delimiters: ");
	gets(Expr);
	return;
}

bool checkDelimiter(char Expr[]) {
    char *marker = Expr;

    NODE stack;
    createStack(&stack);

    while (*marker) { // Loop to cycle through the string
        switch (*marker) {
            case '(':
            case '[':
                push(&stack, *marker);
                break;
            case ')':
                if (isEmpty(stack)) // If the stack is NULL, the program will crash if I do stack->data so this exists
                    return false;

                if (stack -> data == '(') // Check if there's the right delimiter so they cannot be mixed up
                    pop(&stack);
                else
                    return false;
                break;
            case ']':
                if (isEmpty(stack))
                    return false;

                if (stack -> data == '[')
                    pop(&stack);
                else
                    return false;
                break;
        }

        *marker++;
    }

    if (stack != NULL) // Checks if there's any leftover. Happens if stack has ( or [
        return false;

    return true;
}

int main() {
	char expression[SIZE], choice;
	float result;
	bool expressionIsValid;

	do {
        inputExpression(expression);
        expressionIsValid = checkDelimiter(expression);

        if(expressionIsValid)
            printf("%s is balanced.\n", expression);
        else
            printf("Error: %s is unbalanced.\n", expression);

        printf("Type 'q' to quit or anything else to try again: ");
        scanf("%c", &choice);
        fflush(stdin); // In case the input bugs out
        printf("\n");
	} while (choice != 'q');

    printf("Exiting program...\n");
	getch();

	return 0;
}
