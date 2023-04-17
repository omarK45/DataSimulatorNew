#pragma once
#include "Processor.h"
#include "Process.h"
#include "PrioQueue.h"
template <class T>
class FCFS : public Processor
{
private:
	LinkedList<T> ReadyList;
	Queue<T> RunList;

public:
	FCFS();
	void ScheduleAlgo();
	void AddProcessRd(Process* p);
	void AddProcessRn(Process* p);
	LinkedList<T>& getReadyList();
	Queue<T>& getRun();

};