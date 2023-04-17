#pragma once
#include "Processor.h"
#include "Process.h"
#include "Queue.h"
template <typename T>
class RoundRobin :public Processor {
private:
    Process* run;
    Queue<Process> ReadyList;
    Queue<T> RunList;
    int timeslice;
    int timesum;
    Queue<Process> TRM;
public:
    void settimeslice(int t);
    void ScheduleAlgo();
    void AddProcessRd(Process* p);
    void AddProcessRn(Process* p);
    Queue<T>& getReadyList();
    Queue<T>& getRun();

};
