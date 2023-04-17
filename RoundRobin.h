#pragma once
#include "Processor.h"
#include "Process.h"
#include "Queue.h"
class RoundRobin :public Processor {
private:
    Process* run;
    Queue<Process> ReadyList;
    Queue<Process> RunList;
    int timeslice;
    int timesum;
    Queue<Process> TRM;
public:
    void settimeslice(int t);
    void ScheduleAlgo();
    void AddProcessRd(Process p);
    void AddProcessRn(Process p);
    Queue<Process>& getReadyList();
    Queue<Process>& getRun();

};
