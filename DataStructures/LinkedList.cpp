#include "LinkedList.h"
#include <iostream>


LinkedList* createNode(int num)
{
    LinkedList* newLinkedList = new LinkedList;
    newLinkedList->num = num;
    newLinkedList->next = NULL;
    return newLinkedList;
}

void addNode(LinkedList* head, int num)
{
    LinkedList* newLinkedList = createNode(num);
    LinkedList* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newLinkedList;
}

LinkedList* deleteNode(LinkedList* head)
{
    if (head == NULL)  
        return NULL;

    LinkedList* temp = head;
    head = temp->next;
    delete temp;

    return head;
}

