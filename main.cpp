//NAME: Jackson Montaigne
//CLASS: CS303-0002
//DESC: A simple stack and linked list user interface.

#include "main.h"
#include "UserInterface.cpp"

int main()
{
    Stack stack;
    LinkedList list;
    bool running = true;
    while (running)
    {
        running = stack_or_list(stack, list);
    }

    std::cout << "\nGoodbye\n\n";
}