#include "FCFS.h"
FCFS::FCFS()
{
    RunList ;
    status = true;
    Type = "FCFS";
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
        return RunList;
    }
    else
    {
        Process* tmp = RunList;
        RunList = NULL;
        return tmp;
    }
    
}
void FCFS::AddProcessRd(Process* p)
{
	ReadyList.InsertEnd(p);
    Rd = false;
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
void FCFS::printRDY() {
    ReadyList.PrintList();
}


