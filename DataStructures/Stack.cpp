#include "Stack.h"
#include "LinkedList.h"
#include <iostream>



void initStack(Stack* s)
{
	s->head = new LinkedList;
	s->head->next = NULL;
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

	if (isEmpty(s))
	{
		return -1;
	}

	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}

	value = temp->num;
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
	if (s->head->next == NULL || s->head == NULL)
	{
		return true;
	}
	return false;
}
