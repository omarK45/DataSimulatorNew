#include "Node.h"

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
public:

    LinkedList() : head(nullptr) {}

    void insertNode(T data);
    void deleteNode(T value);
    void printlist();
};


