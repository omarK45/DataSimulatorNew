#pragma once
#include "Queue.h"
#include "PrioQueueNode.h"
#include <iostream>
using namespace std;
#pragma once


template<class T>
class PriorityQueue {
	PrioQueueNode<T>* front = NULL;
public:
	int count = 0;
	void insert(T val, float priority)
	{
		PrioQueueNode<T>* temp, * q;
		temp = new PrioQueueNode<T>(val, priority);
		if (front == NULL || priority > front->priority)
		{
			temp->next = front;
			front = temp;
		}
		else
		{
			q = front;
			while (q->next != NULL && q->next->priority >= priority)
				q = q->next;
			temp->next = q->next;
			q->next = temp;
		}
		count++;
	}
	T remove()
	{
		PrioQueueNode<T>* temp;
		if (front != NULL)
		{
			temp = front;
			T data = temp->data;
			front = front->next;
			delete temp;
			count--;
			return data;
		}
	}
	int size()
	{
		return count;
	}
	T ElementAt(int i) {
		if (i > count) return NULL;
		PrioQueueNode<T>* n = front;
		int c = 0;
		while (n != NULL && c < i) {
			n = n->next;
			c++;
		}
		return n->data;
	}
	void display()
	{
		PrioQueueNode<T>* t;
		t = front;
		if (front == NULL)
			printf("Queue is empty\n");
		else
		{
			while (t != NULL)
			{
				cout << t->data << endl;
				t = t->next;
			}
		}
	}
	bool isEmpty()
	{
		return front == NULL;
	}
};
