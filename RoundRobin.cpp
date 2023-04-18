#include "RoundRobin.h"
RoundRobin::RoundRobin() {
    Type="RoundRobin";
}
void RoundRobin::settimeslice(int t) {
    timeslice = t;
}

void RoundRobin::ScheduleAlgo() {

}
void RoundRobin::AddProcessRd(Process p) {
    RDY.enqueue(p);
}

void RoundRobin::AddProcessRn(Process p)
{
    RDY.enqueue(p);
}
Queue<Process>& RoundRobin::getReadyList()
{
    return RDY;
}

Queue<Process>& RoundRobin::getRun()
{
    return RDY;
}



