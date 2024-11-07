#include "Utils.h"
#include "Stack.h"
#include <iostream>


void reverse(int* nums, unsigned int size)
{
    Stack* s = new Stack;
    initStack(s);

    for (int i = 0; i < size; i++)
    {
        push(s, nums[i]);
    }

    for (int i = 0; i < size; i++)
    {
        nums[i] = pop(s);
    }

    delete s;
}

int* reverse10() 
{
    Stack* s = new Stack;
    int max_size = 10;
    int* nums = new int[max_size];
    int num = 0;

    initStack(s);

    for (int i = 0; i < max_size; i++)
    {
        std::cout << "Enter a num: " << std::endl;
        std::cin >> num;
        nums[i] = num;
    }

    for (int i = 0; i < max_size; i++)
    {
        push(s, nums[i]);
    }

    for (int i = 0; i < max_size; i++)
    {
        nums[i] = pop(s);
    }

    delete s;
    return nums;
}