#include "FCFS.h"
FCFS::FCFS()
{
    RunList ;
    status = true;
}
Process* FCFS::ScheduleAlgo()
{
    if (ReadyList.count() == 0)
    {
        return NULL;
    }
    if (status==true)
    {
        Process* ss = ReadyList.DeleteFirst();
        RunList = ss;
        status = false;
        return NULL;
    }
    else
    {
        Process* tmp = RunList;
        ReadyList.DeleteNode(RunList);
        return tmp;
    }
    
}
void FCFS::AddProcessRd(Process* p)
{
	ReadyList.InsertEnd(p);
}

void FCFS::AddProcessRn(Process* p)
{
	RunList = p;
}

Process* FCFS::getRun()
{
    //Make temp = to running
    Process* temp = RunList;
    //Set Running to NULL
    RunList = NULL;
    //return the temp
    return temp;
}


