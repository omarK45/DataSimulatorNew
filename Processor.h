#pragma once
#include "LinkedList.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "Process.h"
template <class T>
class Processor
{
protected:
	LinkedList<Process> ReadyList;
	Queue<Process> RunList;
	int timestep;
	int busytime;
	bool status;
public:
	Processor();
	void virtual AddProcess(Process* P) = 0;
	void virtual ScheduleAlgo() = 0;
	void SetStatus();
	bool GetStatus();
	int virtual PLoad();
	int virtual PUtil();
};