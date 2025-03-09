#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "LinkedList.cpp"
#include "LinkedList.h"

#include "Stack.cpp"
#include "Stack.h"

//POST: Returns natural number input from the user
int get_natural();

//PRE: Takes size of a list
//POST: Returns an index given by the user within the size of the list.
int get_index(int size);

//PRE: Takes a string to be checked
//POST: Returns true if the string is a natural number, false otherwise
bool is_natural(std::string);

//POST: Buffers until the user presses enter.
void buffer();

//POST: Clears the terminal (made by deepseek)
void clear_terminal();

//PRE: Takes a stack and a list object
//POST: Lets user decide whether to use stack or list menu
bool stack_or_list(Stack &stack, LinkedList &list);

//PRE: Takes a stack
//POST: Lets user choose to do various operations on the stack.
bool stack_menu(Stack &stack);

//PRE: Takes a linked list
//POST: Lets user choose to do various operations on the list
bool list_menu(LinkedList &list);
