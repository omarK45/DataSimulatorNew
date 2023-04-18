#include "RoundRobin.h"

RoundRobin::RoundRobin()
{
	status = true;
}
void RoundRobin::settimeslice(int t) {
	timeslice = t;
}

Process* RoundRobin::ScheduleAlgo()
{
	if (ReadyList.isEmpty())
	{
		return NULL;
	}
	if (status == true)
	{
		Process* p;
		ReadyList.dequeue(p);
		RunList = p;
		status = false;
		return NULL;
	}
	else 
	{
		Process* tmp = RunList;
		ReadyList.dequeue(RunList);
		return tmp;
	}
}
void RoundRobin::AddProcessRd(Process* p)
{
	ReadyList.enqueue(p);
}

void RoundRobin::AddProcessRn(Process* p)
{
	RunList = p;
}

Process* RoundRobin::getRun()
{
	//Make temp = to running
	Process* temp = RunList;
	//Set Running to NULL
	RunList = NULL;
	//return the temp
	return temp;
}



