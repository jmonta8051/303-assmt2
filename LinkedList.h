#pragma once

#include <iostream>

struct Node
{
    int data;
    Node* next = nullptr;
};

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int numItems;
    
    public:
        LinkedList()
        {
            this->head = nullptr;
            this->tail = nullptr;
            this->numItems = 0;
        }
        
        //Getters
        Node* front()   { return head; }
        Node* back()    { return tail; }
        int size()      { return numItems; }
        
        //Setters
        void set_front(Node* front) { this->head = front; }
        void set_back(Node* back)   {this->tail = back; }
        void set_size(int size)     { this->numItems = size; }

        //Functions
        void push_front(int data);
        void push_back(int data);
        Node* pop_front();
        Node* pop_back();
        bool empty();
        void insert(int index, int data);
        bool remove(int index);
        int  find(int data);
        void print_list();
};