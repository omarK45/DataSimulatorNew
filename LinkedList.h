#include "Node.h"
#pragma once
template<typename T>
class LinkedList
{
private:
    Node<T>* head;
    int count;
public:

    LinkedList()  {
        head = nullptr;
        count = 0;
    }
    T getdata();
    void insertNode(T data);
    void deleteNode(T value);
    void printlist();
    bool deleteLastNode();
    bool isempty();
    int getlistcount();
};


