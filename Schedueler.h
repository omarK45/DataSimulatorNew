#ifndef SCHEDUELER_H
#define SCHEDUELER_H

#include "LinkedList.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RoundRobin.h"
#include "Processor.h"

class Schedueler
{
protected:
    Queue<Process> newlist;
    Queue<Process> Blk;
    Queue<Process> TRM;
    int timestep = 0;
    int NF, NS, NR;
    FCFS* arrF;
    SJF* arrS;
    RoundRobin* arrR;
    bool click;

public:
    Schedueler();
    void load();
    void simulate();
};

#endif
