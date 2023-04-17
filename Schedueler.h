#pragma once
#include "LinkedList.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RoundRobin.h"
#include "Processor.h"
class Schedueler
{
protected:
	Queue<Process> newlist;
	Queue<Process> Blk;
	Queue<Process> TRM;
	int timestep;
	int NF, NS, NR;
	FCFS<Process>* arrF;
	SJF<Process>* arrS;
	RoundRobin<Process>* arrR;

public:
	Schedueler();
	void load();
	void simulate();
};
