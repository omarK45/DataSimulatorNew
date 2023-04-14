#include "RoundRobin.h"
template <typename T>
void RoundRobin<T>::settimeslice(int t) {
    timeslice=t;
}
template <typename T>
void RoundRobin<T>::ScheduleAlgo(){
    Process p;
    int timetaken=0;
    while(timesum!=timetaken){
        p = RDY.dequeue();
        if(p.time_remaining!=0){
            if(p.time_remaining>=timeslice){
                run =&p;
                p.time_remaining-=timeslice;
                timetaken+=timeslice;
                RDY.enqueue(p);
            }
            else{
                timetaken+=p.time_remaining;
                run=&p;
                p.time_remaining=0;
                TRM.enqueue(p);
            }
        }
    }
}
template <typename T>
void RoundRobin<T>::addprocess(Process p){
RDY.enqueue(p);
timesum+=p.time_remaining;
}