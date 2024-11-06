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




