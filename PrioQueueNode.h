#pragma once
using namespace std;
template<class T>
class PrioQueueNode
{
public:
	int priority = 0;
	T data;
	PrioQueueNode<T>* next = NULL;
	PrioQueueNode(T d, int p) {
		data = d;
		priority = p;
	}
};
