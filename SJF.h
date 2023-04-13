#pragma once
#include "Processor.h"
#include "PrioQueue.h"

template <class T>
class SJF :public Processor<T>
{
private:
	PriorityQueue<T> ReadyList;
	int priority;
public:
	void virtual ScheduleAlgo();
	void AddProcess(Process* p);
};

