#pragma once
#include "Processor.h"
#include "PrioQueue.h"


class SJF :public Processor
{
private:
	PriorityQueue<Process> ReadyList;
	Queue<Process> RunList;
	int priority;
public:
	void virtual ScheduleAlgo();
	void AddProcessRd(Process p);
	void AddProcessRn(Process p);
	PriorityQueue<Process>& getReadyList();
	Queue<Process>& getRun();
};
