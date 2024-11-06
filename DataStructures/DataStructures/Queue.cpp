#include "Queue.h"
#include <iostream>

void initQueue(Queue* q, unsigned int size)
{
    q->_maxSize = size;
    q->_elements = new int[q->_maxSize];
    q->_count = 0;
    for (int i = 0; i < q->_maxSize; i++)
    {
        q->_elements[i] = -9;
    }
}

void enqueue(Queue* q, unsigned int newValue)
{

    if (q->_count == q->_maxSize)
    {
        std::cout << "MAX num of Queue" << std::endl;
    }
    else
    {
        q->_elements[q->_count] = newValue;
        q->_count++;
    }
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    int return_value = 0;
    return_value = q->_elements[0];

    for (int i = 0; i < q->_maxSize; i++)
    {
        q->_elements[i] = q->_elements[i + 1];
    }
    q->_elements[q->_maxSize - 1] = -9;
    return return_value;

}

void cleanQueue(Queue* q)
{
    for (int i = 0; i < q->_maxSize; i++)
    {
        q->_elements[i] = -9;
    }
}

bool isEmpty(Queue* s)
{
    int count = 0;
    for (int i = 0; i < s->_maxSize; i++)
    {
        if (s->_elements[i] == -9)
        {
            count++;
        }
    }
    if (count == s->_maxSize)
    {
        return true;
    }
    return false;
}

bool isFull(Queue* s)
{
    for (int i = 0; i < s->_maxSize; i++)
    {
        if (s->_elements[i] == -9)
        {
            return false;
        }
    }
    return true;
}