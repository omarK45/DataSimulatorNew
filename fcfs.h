#pragma once
#include "Processor.h"
#include "Process.h"
#include "PrioQueue.h"

class FCFS : public Processor
{
private:
	LinkedList<Process> ReadyList;
	Queue<Process> RunList;

public:
	FCFS();
	void ScheduleAlgo();
	void AddProcessRd(Process p);
	void AddProcessRn(Process p);
	LinkedList<Process>& getReadyList();
	Queue<Process>& getRun();

};