#pragma once
#include "Processor.h"
#include "Process.h"
#include "Queue.h"
template <typename T>
class RoundRobin:public Processor<T>{
private:
    Process*run;
    Queue<Process> RDY;
    int timeslice;
    int timesum;
    Queue<Process> TRM;
public:
    void settimeslice(int t);
    void ScheduleAlgo();
    void addprocess(Process p);

};



