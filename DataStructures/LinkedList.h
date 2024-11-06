#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

typedef struct LinkedList
{
	int value;
	LinkedList* next;
}LinkedList;

LinkedList* createLinkedList(int value);
void addNode(LinkedList* head, int value);
void printLinkedList(LinkedList* head);
LinkedList* deleteHeadNode(LinkedList* head);

#endif