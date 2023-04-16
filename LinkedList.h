#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    T data;
    int count;

public:
    T getdata();
    void insertNode(T data);
    void deleteNode(T value);
    void printlist();
    bool deleteLastNode();
    bool isempty();
    int getlistcount();
};


#endif 



