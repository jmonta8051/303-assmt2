#include "LinkedList.h"

void LinkedList::push_front(int data)
{
    //Node to be added
    Node* newHead = new Node();
    newHead->data = data;

    //Handles empty list
    if (this->head == nullptr)
        this->tail = newHead;

    //Adds to front
    newHead->next = this->head;
    this->head = newHead;
    this->numItems++;
}

void LinkedList::push_back(int data)
{
    //Node to be added
    Node* newTail = new Node();
    newTail->data = data;

    //Handles empty list
    if (this->head == nullptr)
    {
        this->head = newTail;
        this->tail = newTail;
        this->numItems++;
        return;
    }

    //Adds to back
    this->tail->next = newTail;
    this->tail = newTail;
    numItems++;
}

Node* LinkedList::pop_front()
{
    //Handles empty list
    if (this->head == nullptr)
        return nullptr;

    //Saves for return
    Node* pop = head;

    //Removes head
    this->head = this->head->next;
    this->numItems--;

    return pop;
}

Node* LinkedList::pop_back()
{
    //Handles empty list
    if (this->head == nullptr)
        return nullptr;

    //Saves for return
    Node* pop = this->tail;

    //Iterates until second to last item
    Node* iterator = this->head;
    while (iterator->next != this->tail)
        iterator = iterator->next;

    //Cuts off tail
    iterator->next = nullptr;
    this->tail = iterator;
    this->numItems--;

    return pop;
}

bool LinkedList::empty()
{
    return numItems <= 0;
}

void LinkedList::insert(int index, int data)
{
    //Node to be added
    Node* newItem = new Node();
    newItem->data = data;

    //Adding to front or back is identical to push_front or push_back 
    if (index <= 0)                 { this->push_front(data); return; }
    if (index >= this->numItems)    { this->push_back(data); return; }

    //Iterates until one before index
    Node* iterator = this->head;
    for (int i = 0; i < index - 1; ++i)
        iterator = iterator->next;

    //Inserts new value
    newItem->next = iterator->next;
    iterator->next = newItem;
    numItems++;
}

bool LinkedList::remove(int index)
{
    //Handles index out of range
    if (index >= this->numItems || index < 0) { return false; }

    //Removing from front or back is identical to pop_front or pop_back
    if (index == 0)                     { this->pop_front(); return true; }
    if (index == this->numItems - 1)    { this->pop_back(); return true; }

    //Iterates until one before index
    Node* iterator = this->head;
    for (int i = 0; i < index - 1; ++i)
        iterator = iterator->next;

    //Saves node for deletion
    Node* toBeDeleted = iterator->next;

    //Cuts out node
    iterator->next = iterator->next->next;
    this->numItems--;

    delete toBeDeleted;

    return true;
}

int  LinkedList::find(int data)
{
    //Iterates until the end of list
    int index = 0;
    Node* iterator = this->head;
    while (iterator != nullptr)
    {   
        //Returns if the item is found
        if (iterator->data == data) { return index; }
        
        iterator = iterator->next;
        index++;
    }
    return index;
}

void LinkedList::print_list()
{
    Node* iterator = this->head;
    while (iterator != nullptr)
    {
        std::cout << iterator->data << "\n";
        iterator = iterator->next;
    }
}