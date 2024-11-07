#include "LinkedList.h"
#include <iostream>


LinkedList* createLinkedList(int value)
{
    LinkedList* newLinkedList = new LinkedList;
    newLinkedList->value = value;
    newLinkedList->next = NULL;
    return newLinkedList;
}

void addNode(LinkedList* head, int value)
{
    LinkedList* newLinkedList = createLinkedList(value);
    LinkedList* temp = head;
    while (temp)
    {
        temp = temp->next;
    }
    temp = newLinkedList;
}

void printLinkedList(LinkedList* head)
{
    LinkedList* temp = head;
    while (temp)
    {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
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

