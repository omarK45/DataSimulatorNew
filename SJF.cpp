#include "SJF.h"

SJF::SJF()
{
    status = true;
    RunList = NULL;
}
Process* SJF::ScheduleAlgo()
{
    if (ReadyList.isEmpty())
    {
        return NULL;
    }
    if (status==true)
    {
        RunList = ReadyList.dequeue();
        status = false;
        return RunList;
    }
    else
    {
        return RunList;
    }
}



void SJF::AddProcessRd(Process* p)
{
	ReadyList.enqueue(*p, p->getcpu_time());
}

void SJF::AddProcessRn(Process* p)
{
	RunList = p;
    Rd = false;
}


Process* SJF::getRun()
{
    //Make temp = to running
    Process* temp = RunList;
    //Set Running to NULL
    RunList = NULL;
    //return the temp
    return temp;
}
void SJF::printRDY() {
   
}