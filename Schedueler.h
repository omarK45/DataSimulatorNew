#pragma once
#include "LinkedList.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
class Schedueler
{
protected:
	LinkedList<Process> newlist;
	int timestep;

public:
	Schedueler();
	void load();
	void simulate();
};

