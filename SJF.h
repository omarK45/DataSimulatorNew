#pragma once
#include "Processor.h"
#include "PrioQueue.h"


class SJF :public Processor
{
private:
	PriorityQueue<Process> ReadyList;
	Process* RunList;
	int priority;
public:
	SJF();
	virtual Process* ScheduleAlgo();
	void AddProcessRd(Process* p);
	void AddProcessRn(Process* p);
	Process* getRun();
};
