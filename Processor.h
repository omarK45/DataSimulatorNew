#pragma once
#include "LinkedList.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "Process.h"

class Processor
{
protected:
	int timestep;
	int busytime;
	bool status;
	bool Rd;
	Process* RunList;
public:
	Processor();
	void virtual AddProcessRd(Process* P) = 0;
	virtual Process* ScheduleAlgo() = 0;
	void SetStatus(bool s);
	bool GetStatus();
	bool Empty();
	virtual Process* getRun() = 0;
	int virtual PLoad();
	int virtual PUtil();
};