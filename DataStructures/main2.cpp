#include "Stack.h"
#include <iostream>

int main()
{
	Stack* s = new Stack;
	initStack(s);
	push(s, 8);
	push(s, 9);
	push(s, 5);
	push(s, 2);

	return 0;
}