#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }


    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};