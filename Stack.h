#pragma once

#include <iostream>
#include <vector>

class Stack
{
    private:
        std::vector<int> data;
        int numItems;
    
    public:
        Stack() { numItems = 0; }

        //Getter
        int front();

        //Setters
        int pop();
        void push(int item);

        //Functions
        bool empty();
        float average();
        void print();
};