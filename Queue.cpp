#include "Queue.h"
#include <iostream>
using namespace std;

template<typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void Queue<T>::enqueue(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    Node<T>* temp = head;
    T value = head->data;
    head = head->next;
    delete temp;
    return value;
}

template<typename T>
T Queue<T>::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;

    }
    return head->data;
}

template<typename T>
void Queue<T>::printQueue() {
    if (isEmpty()) {
      cout << "Queue is empty";
    }
    else {
        Node<T>* temp = head;
     cout << "Queue=";
        while (temp != nullptr) {
           cout << temp->data << " , ";
            temp = temp->next;
        }
  
    }
}

template<typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}
