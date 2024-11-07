#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

typedef struct LinkedList
{
	int num;
	LinkedList* next;
}LinkedList;

LinkedList* createNode(int num);
void addNode(LinkedList* head, int num);
LinkedList* deleteNode(LinkedList* num);

#endif