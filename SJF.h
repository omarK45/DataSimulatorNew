#pragma once
#include "Processor.h"
#include "PrioQueue.h"

template <class T>
class SJF :public Processor
{
private:
	PriorityQueue<T> ReadyList;
	Queue<T> RunList;
	int priority;
public:
	void virtual ScheduleAlgo();
	void AddProcessRd(Process* p);
	void AddProcessRn(Process* p);
	Queue<T>& getReadyList();
	Queue<T>& getRun();
};
