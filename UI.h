#include <iostream>
#include "Queue.h"
#include "PrioQueue.h"
#include "Process.h"
#include "Processor.h"
using namespace std;
class UI {
    void print(Processor*p[],int numprocessor,Queue<Process>*blk,Process*run[],PriorityQueue<Process>*trm,int timestep );
};
