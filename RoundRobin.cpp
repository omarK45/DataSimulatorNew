#include "RoundRobin.h"
void RoundRobin::settimeslice(int t) {
    timeslice = t;
}

void RoundRobin::ScheduleAlgo() {

}
void RoundRobin::AddProcessRd(Process p) {
    ReadyList.enqueue(p);
}

void RoundRobin::AddProcessRn(Process p)
{
    RunList.enqueue(p);
}
Queue<Process>& RoundRobin::getReadyList()
{
    return ReadyList;
}

Queue<Process>& RoundRobin::getRun()
{
    return RunList;
}



