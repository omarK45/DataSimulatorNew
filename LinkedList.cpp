
#include "LinkedList.h"
template<typename T>
void LinkedList<T>::insertNode(T data)
{
    Node<T>* newNode = new Node<T>(data);


    if (head == nullptr) {
        head = newNode;
        count += 1;
        return;

    }

    Node<T>* temp = head;
    while (temp->next != nullptr) {

        temp = temp->next;
    }

    temp->next = newNode;
    count += 1;
}

template<typename T>
bool LinkedList<T>::isempty() {
    if (head == nullptr) {
        return false
    else
        return true;
    }
        

}

template<typename T>
void LinkedList<T>::deleteNode(T value) {
    Node<T>* currNode = head;
    Node<T>* prevNode = nullptr;

    while (currNode != nullptr && currNode->data != value) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If the node is found, delete it
    if (currNode != nullptr) {
        if (currNode == head) {
            head = currNode->next;
        }
        else {
            prevNode->next = currNode->next;
        }
        delete currNode;
    }
}
template <typename T>
void LinkedList<T>::printlist()
{
    Node<T>* temp = head;

    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
        count--;
        return true;
    }
    Node<T>* currNode = head;
    Node<T>* prevNode = nullptr;
    while (currNode->next != nullptr) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = nullptr;
    delete currNode;
    count--;
    return true;
}

template<typename T>
int LinkedList<T>::getlistcount() {
    cout <<"count=" << count;
    return count;
}




