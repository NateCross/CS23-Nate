#include <stdio.h>
#include <string.h>
#include "STACK.H"

#define M 100

void inputExpression(char []);
void checkExpDelimeter(char []);
void displayResult(char [], bool);

int main(void)
{
	char expr[M];
	memset(expr,'\0',M);
	inputExpression(expr);
	checkExpDelimeter(expr);
	return 0;
}

void inputExpression(char exp[])
{
	printf("\n\n\tInput a parenthesized expression: ");
	gets(exp);
	return;
}

void checkExpDelimeter(char exp[])
{
	bool balExp = true, empty;
	char delim, rDelim;
	int j = 0;
	nd tos;
	createStack(&tos);
	while(exp[j] != '\0')// a for...loop can be used but needs to use the length of the string as limits
	{
		delim = exp[j];
		if (delim == '(')
			push(&tos,delim);
		else if (delim == ')')
		{
			empty = isEmpty(tos);
			if (!empty)
				rDelim = pop(&tos);
			else
			{
				balExp = false;
				break;
			}
		}
		j++;
	}// end of while(expr[j] != '\0')
	empty = isEmpty(tos);
	if(!empty)
		balExp = false;
	displayResult(exp,balExp);
	return;
}
void displayResult(char expr[], bool balExp)
{
	if (balExp)
		printf("\n\n\tThe expression %s has balance delimiters...",expr);
	else
		printf("\n\n\tThe expression %s has an unbalance delimiters...",expr);
	getch();
	return;
}

