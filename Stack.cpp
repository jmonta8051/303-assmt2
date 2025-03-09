#include "Stack.h"

int Stack::front()
{
    if (this->empty()) { return -1; }
    return this->data.at(0);
}

int Stack::pop()
{
    if (this->empty()) { return -1; }
    
    //Save for return
    int pop = this->data.at(0);

    //Deletes first item in vector
    this->data.erase(data.begin());
    this->numItems--;

    return pop;
}

void Stack::push(int item)
{
    //Adds item to front of vector
    this->data.insert(data.begin(), item);
    this->numItems++;
}

bool Stack::empty()
{
    return numItems <= 0;
}

float Stack::average()
{  
    if (this->empty()) { return 0; }

    //Adds values, divides by size
    int accumulation = 0;
    for (auto i : this->data) { accumulation += i; }
    return accumulation / static_cast<float>(this->numItems);
}

void Stack::print()
{
    std::cout << "Size - " << this->numItems << "\n\n";
    for (auto i : this->data)
    {
        std::cout << i << "  ";
    }
    std::cout << "\n";
}