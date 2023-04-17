#pragma once
#include "LinkedList.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "Processor.h"

class Schedueler
{
protected:
	LinkedList<Process> newlist;
	int timestep;
	FCFS<Process>* arrF;
	SJF<Process>* arrS;

public:
	Schedueler();
	void load();
	void simulate();
};
