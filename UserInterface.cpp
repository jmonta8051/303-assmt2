#include "main.h"

int get_natural()
{
    std::string input;
    std::getline(std::cin, input);

    //Loops until natural number is entered
    while (!is_natural(input) || input.size() <= 0)
    {
        std::cout << "ERROR - Try again: ";
        std::getline(std::cin, input);
    }

    return std::stoi(input);
}

int get_index(int size)
{
    int index = get_natural();
    while (index >= size)
    {  
        //Handles inserting into an empty list
        if (index == 0 && size == 0) { return index; }

        std::cout << "ERROR - Out of range, try again: ";
        index = get_natural();
    }
    return index;
}

bool is_natural(std::string testValue)
{
    if (testValue.find_first_not_of("1234567890") == std::string::npos)
        return true;
    return false;
}

void buffer()
{
    std::cout << "\nPress enter to continue...";
    std::string temp;
    std::getline(std::cin, temp);
}

//DeepSeek Prompt "universal clear terminal command in cpp"
void clear_terminal()
{
    #ifdef _WIN32
        // Windows
        system("cls");
    #else
        // Linux, macOS, and other Unix-like systems
        system("clear");
    #endif
}

bool stack_or_list(Stack &stack, LinkedList &list)
{
    clear_terminal();

    std::cout
        << "    Would you like to perform stack or list operations?\n"
        << " 1. Stack\n"
        << " 2. List\n"
        << " 3. Close Program\n"
        << "Choice: ";

    std::string input;
    std::getline(std::cin, input);

    bool running = true;

    //Loops until user chooses to exit stack or list menus
    switch (input[0])
    {
        case '1': //Stack menu
            while (running)
                running = stack_menu(stack);
            return true;
        
        case '2': //List menu
            while (running)
                running = list_menu(list);
            return true;

        case '3': //Close program
            return false;
    }
    return true;
}

bool stack_menu(Stack &stack)
{
    clear_terminal();

    std::cout
        << "    What stack operation would you like to perform?\n"
        << " 1. Push to front\n"
        << " 2. Pop front\n"
        << " 3. Check empty\n"
        << " 4. Average\n"
        << " 5. Check front\n"
        << " 6. Print stack\n"
        << " 7. Exit\n"
        << "Choice: ";
    
    std::string input;
    std::getline(std::cin, input);

    switch (input[0])
    {
        case '1': //Push to front
        {
            std::cout << "Natural number to push: ";
            int pushValue = get_natural();

            stack.push(pushValue);

            std::cout << pushValue << " pushed to front.\n";
            buffer();
            return true;
        }
        case '2': //Pop from front
            if (!stack.empty()) { std::cout << "Popped " << stack.pop() << " from stack.\n"; }
            else { std::cout << "Stack already empty.\n"; }

            buffer();
            return true;
        
        case '3': //Check if empty
            if (stack.empty()) { std::cout << "The stack is empty.\n"; }
            else { std::cout << "The stack is not empty.\n"; }

            buffer();
            return true;
        
        case '4': //Calculate average
            std::cout << "The average value is " << stack.average() << "\n";
            buffer();
            return true;

        case '5': //Check first value
            if (!stack.empty()) { std::cout << "The first value is " << stack.front() << "\n"; }
            else { std::cout << "The stack is empty.\n"; }
            
            buffer();
            return true;

        case '6': //Print stack
            stack.print();
            buffer();
            return true;

        case '7': //Exit
            return false;
    }
    return true;
}

bool list_menu(LinkedList &list)
{
    clear_terminal();

    std::cout
        << "    What list operation would you like to perform?\n"
        << " 1. Push to front\n"
        << " 2. Push back\n"
        << " 3. Pop front\n"
        << " 4. Pop back\n"
        << " 5. Check empty\n"
        << " 6. Insert at index\n"
        << " 7. Remove at index\n"
        << " 8. Find value\n"
        << " 9. Print list\n"
        << " 0. Exit\n"
        << "Choice: ";
    
    std::string input;
    std::getline(std::cin, input);

    switch (input[0])
    {
        case '1': //Push to front
        {
            std::cout << "Natural number to push: ";
            int pushValue = get_natural();

            list.push_front(pushValue);

            std::cout << pushValue << " pushed to front.\n";
            buffer();
            return true;
        }

        case '2': //Push to back
        {
            std::cout << "Natural number to push: ";
            int pushValue = get_natural();

            list.push_back(pushValue);

            std::cout << pushValue << " pushed to back.\n";
            buffer();
            return true;
        }
        
        case '3': //Pop from front
            if (!list.empty()) { std::cout << "Popped " << list.pop_front()->data << " from front of list.\n"; }
            else { std::cout << "List already empty.\n"; }

            buffer();
            return true;
        
        case '4': //Pop from back
            if (!list.empty()) { std::cout << "Popped " << list.pop_back()->data << " from back of list.\n"; }
            else { std::cout << "List already empty.\n"; }

            buffer();
            return true;

        case '5': //Check if list is empty
            if (list.empty()) { std::cout << "The list is empty.\n"; }
            else { std::cout << "The list is not empty.\n"; }

            buffer();
            return true;

        case '6': //Insert a value at an index
        {
            std::cout << "Natural number to insert: ";
            int insertValue = get_natural();

            std::cout << "Insert at index: ";
            int index = get_index(list.size());

            list.insert(index, insertValue);

            std::cout << insertValue << " inserted at index " << index << "\n";
            buffer();
            return true;
        }

        case '7': //Remove an index
        {
            if (list.size() == 0)
            {
                std::cout << "List already empty.\n";
                buffer();
                return true;
            }

            std::cout << "Index to remove: ";
            int index = get_index(list.size());

            list.remove(index);

            std::cout << "Item at index " << index << " removed.\n";
            buffer();
            return true;
        }

        case '8': //Find a value at an index
        {
            std::cout << "Enter a value to search for: ";
            int findValue = get_natural();

            std::cout << "Item at index " << list.find(findValue) << "\n";
            if (list.find(findValue) == list.size()) { std::cout << " (Item not found)\n"; }
            buffer();

            return true;
        }

        case '9': //Print list
            list.print_list();
            buffer();
            return true;

        case '0': //Exit
            return false;
    }
    return true;
}