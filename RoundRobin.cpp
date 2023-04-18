#include "RoundRobin.h"

RoundRobin::RoundRobin()
{
    Type="Roundrobin";
	status = true;
}
void RoundRobin::settimeslice(int t) {
	timeslice = t;
}

Process* RoundRobin::ScheduleAlgo
()
{
	if (ReadyList.isEmpty())
	{
		return NULL;
	}
	if (status == true)
	{
		RunList = ReadyList.dequeue();
		status = false;
		return NULL;
	}
	else 
	{
		return RunList;
	}
}
void RoundRobin::AddProcessRd(Process* p)
{
	ReadyList.enqueue(p);
	Rd = false;
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
void RoundRobin::printRDY() {
    while(!ReadyList.isEmpty()){
        cout<<ReadyList.dequeue()->getprocess_id()<<" ";
    }
}



