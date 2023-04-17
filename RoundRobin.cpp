#include "RoundRobin.h"
template <typename T>
void RoundRobin<T>::settimeslice(int t) {
    timeslice = t;
}
template <typename T>
void RoundRobin<T>::ScheduleAlgo() {

}
template <typename T>
void RoundRobin<T>::AddProcessRd(Process* p) {
    ReadyList.enqueue(p);
}
template<typename T>
void RoundRobin<T>::AddProcessRn(Process* p)
{
    RunList.enqueue(p);
}
template <class T>
Queue<T>& RoundRobin<T>::getReadyList()
{
    return ReadyList;
}

template<typename T>
Queue<T>& RoundRobin<T>::getRun()
{
    return RunList;
}



