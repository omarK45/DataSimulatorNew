#include "SJF.h"

SJF::SJF() {
    Type="SJF";
}
void SJF::ScheduleAlgo()
{
	
}



void SJF::AddProcessRd(Process p)
{
	ReadyList.insert(p,p.getcpu_time());
}

void SJF::AddProcessRn(Process p)
{
	RunList.enqueue(p);
}

PriorityQueue<Process>& SJF::getReadyList()
{
	return ReadyList;
}

Queue<Process>& SJF::getRun()
{
	return RunList;
}
void SJF::printRDY() {
    ReadyList.printQueue();
}
