#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
    int count;
public:

    LinkedList() {
        head = nullptr;
        count = 0;
    }
    T getdata();
    void insertNode(T data);
    void deleteNode();
    void printlist();
    bool deleteLastNode();
    bool isempty();
    int getlistcount();
};

#endif 
