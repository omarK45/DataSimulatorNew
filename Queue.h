#include "Node.h"

template<typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Queue();
    bool isEmpty();
    void enqueue(T value);
    T dequeue();
    T peek();
    void printQueue();
    ~Queue();
};


