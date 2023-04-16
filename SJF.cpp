#include "SJF.h"

template <typename T>
void SJF<T>::ScheduleAlgo()
{
	Processor<T> p;
	if (p.GetStatus() == true)
	{
		AddProcess();
		p.SetStatus(false);
	}
}


template <typename T>
void SJF<T>::AddProcess(Process* p)
{
	ReadyList.insert(p, priority);
}