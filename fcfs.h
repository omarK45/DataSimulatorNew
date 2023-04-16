#pragma once
#include "Processor.h"
#include "PrioQueue.h"
template <class T>
class FCFS : public Processor<T>
{
private:
   LinkedList<T> ReadyList;
   LinkedList<T> RunList;
public:
	FCFS();
	void virtual ScheduleAlgo();
	void AddProcess(Process* p);

};