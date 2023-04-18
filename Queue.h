#include "Node.h"
#pragma once
template<typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int count=0;

public:
    Queue();
    bool isEmpty();
    void enqueue(T value);
    T dequeue();
    T peek();
    void printQueue();
    int getcount();
    ~Queue();
};


