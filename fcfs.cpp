#include "FCFS.h"
FCFS::FCFS() {
    Type="FCFS";
}
void FCFS::ScheduleAlgo()
{

}
void FCFS::AddProcessRd(Process p)
{
   ReadyList.insertNode(p);
}

void FCFS::AddProcessRn(Process p)
{
    RunList.enqueue(p);
}


LinkedList<Process>& FCFS::getReadyList()
{
    return ReadyList;
}
Queue<Process>& FCFS::getRun()
{
    return RunList;
}

