#pragma once
#include "Processor.h"
#include "PrioQueue.h"
template <class T>
class FCFS : public Processor<T>
{
	private:
		PriorityQueue<T> ReadyList;
		int priority;
	public:
		void virtual ScheduleAlgo();
		void AddProcess(Process* p);

};

