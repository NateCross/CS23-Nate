#include <stdbool.h>
#include <stdlib.h>

typedef struct node *nd;
struct node
{
	  char chr;
       nd next;
}NODE;

bool isEmpty(nd tos)
{
	bool empty = false;
	if (tos == NULL)
		empty = true;
	return empty;
}

void createStack(nd *tos)
{
	*tos = NULL;
}

void push(nd *tos, char symbol)
{
	nd temp = malloc(sizeof(NODE));
	temp->chr = symbol;
	temp->next = NULL;
	
	if (*tos != NULL)
		temp->next = *tos;
	*tos = temp;	
	return;
}
 char pop(nd *tos)
 {
 	char symbol = (*tos)->chr;
 	nd tp = *tos;
 	*tos = (*tos)->next;
 	free(tp);
 	return symbol;
 }
