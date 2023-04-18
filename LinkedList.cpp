#include "LinkedList.h"

template<typename T>
T LinkedList<T>::getdata() {
    if (head != nullptr) {
        return head->data;
    }
    else {
        // You can choose to throw an exception here, or return a default value of T.
        // Here, we choose to throw an exception.
        throw std::out_of_range("List is empty");
    }
}

template<typename T>
void LinkedList<T>::insertNode(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
}

template<typename T>
bool LinkedList<T>::isempty() {
    return (head == nullptr);
}

template<typename T>
void LinkedList<T>::deleteNode() {
    if (head == nullptr) {
        return; 
    }
    Node<T>* nodeToDelete = head;
    head = head->next;
    delete nodeToDelete;
    count--;
}
template <typename T>
void LinkedList<T>::printlist() {
    Node<T>* temp = head;
    if (temp == nullptr) {
        cout << "List empty" << endl;
    }
    else {
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

template<typename T>
bool LinkedList<T>::deleteLastNode() {
    if (head == nullptr) {
        return false;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node<T>* currNode = head;
        Node<T>* prevNode = nullptr;
        while (currNode->next != nullptr) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = nullptr;
        delete currNode;
    }
    count--;
    return true;
}

template<typename T>
int LinkedList<T>::getlistcount() {
    return count;
}
