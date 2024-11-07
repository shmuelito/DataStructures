#include "Stack.h"
#include "LinkedList.h"
#include <iostream>



void initStack(Stack* s)
{
	s->head = new LinkedList;
	s->head = NULL;
}

void push(Stack* s, unsigned int element)
{
	addNode(s->head, element);
}

int pop(Stack* s)
{
	int value = 0;
	LinkedList* temp = s->head;
	LinkedList* prev = NULL;

	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}

	value = temp->value;
	deleteNode(temp);
	prev->next = NULL;

	return value;
}

void cleanStack(Stack* s)
{
	LinkedList* curr = s->head; 
	LinkedList* temp = NULL;

	while (curr)
	{
		temp = curr->next;
		delete curr; 
		curr = temp; 
	}
}

bool isEmpty(Stack* s)
{
	return(s->head->next == NULL || s->head == NULL);
}
