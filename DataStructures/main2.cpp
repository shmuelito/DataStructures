#include "Stack.h"
#include "Utils.h"
#include "Queue.h"
#include <iostream>

int main()
{
    int mainChoice = 0;

    while (mainChoice != 3)
    {
        std::cout << "MAIN MENU" << std::endl;
        std::cout << "1. Stack Menu" << std::endl;
        std::cout << "2. Queue Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> mainChoice;

        if (mainChoice == 1) 
        {
            Stack* s = new Stack;
            initStack(s);
            int stackChoice = 0;
            int num = 0;

            while (stackChoice != 6)
            {
                std::cout << "\nSTACK MENU" << std::endl;
                std::cout << "1. Push" << std::endl;
                std::cout << "2. Pop" << std::endl;
                std::cout << "3. Clean Stack" << std::endl;
                std::cout << "4. Check if Empty" << std::endl;
                std::cout << "5. Return to Main Menu" << std::endl;
                std::cout << "Choose an option: ";
                std::cin >> stackChoice;

                switch (stackChoice)
                {
                case 1:
                    std::cout << "Enter number to push: ";
                    std::cin >> num;
                    push(s, num);
                    break;
                case 2:
                    std::cout << "Popped: " << pop(s) << std::endl;
                    break;
                case 3:
                    cleanStack(s);
                    std::cout << "Stack cleaned." << std::endl;
                    break;
                case 4:
                    std::cout << "Stack is empty: " << isEmpty(s) << std::endl;
                    break;
                case 5:
                    delete s;
                    stackChoice = 6; 
                    break;
                default:
                    std::cout << "Choose a number between 1-5." << std::endl;
                    break;
                }
                std::cout << "\n";
            }
        }
        else if (mainChoice == 2) 
        {
            Queue* q = new Queue;
            unsigned int size;

            std::cout << "Enter queue size: ";
            std::cin >> size;
            initQueue(q, size);

            int queueChoice = 0;
            int num = 0;

            while (queueChoice != 6)
            {
                std::cout << "\nQUEUE MENU" << std::endl;
                std::cout << "1. Enqueue" << std::endl;
                std::cout << "2. Dequeue" << std::endl;
                std::cout << "3. Clean Queue" << std::endl;
                std::cout << "4. Check if Empty" << std::endl;
                std::cout << "5. Check if Full" << std::endl;
                std::cout << "6. Return to Main Menu" << std::endl;
                std::cout << "Choose an option: ";
                std::cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    std::cout << "Enter number to enqueue: ";
                    std::cin >> num;
                    enqueue(q, num);
                    break;
                case 2:
                    std::cout << "Dequeued: " << dequeue(q) << std::endl;
                    break;
                case 3:
                    cleanQueue(q);
                    std::cout << "Queue cleaned." << std::endl;
                    break;
                case 4:
                    std::cout << "Queue is empty: " << isEmpty(q) << std::endl;
                    break;
                case 5:
                    std::cout << "Queue is full: " << isFull(q) << std::endl;
                    break;
                case 6:
                    delete q;
                    queueChoice = 6;
                    break;
                default:
                    std::cout << "Choose a number between 1-6." << std::endl;
                    break;
                }
                std::cout << "" << std::endl;
            }
        }
        else if (mainChoice != 3)
        {
            std::cout << "Choose a number between 1-3." << std::endl;
        }
    }

    std::cout << "Bye Bye :)." << std::endl;
    return 0;
}
