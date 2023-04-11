
#include "LinkedList.h"
template<typename T>
void LinkedList<T>::insertNode(T data)
{
    // Create the new Node.
    Node<T>* newNode = new Node<T>(data);

    // Assign to head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node<T>* temp = head;
    while (temp->next != nullptr) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
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


