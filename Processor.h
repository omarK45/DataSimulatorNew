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
public:
	Processor();
	void virtual AddProcessRd(Process* P) = 0;
	void virtual ScheduleAlgo() = 0;
	void SetStatus(bool s);
	bool GetStatus();
	int virtual PLoad();
	int virtual PUtil();
};