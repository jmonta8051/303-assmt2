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