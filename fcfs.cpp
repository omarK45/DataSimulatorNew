#include "FCFS.h"
template <typename T>
FCFS<T>::FCFS(){



}
template <typename T>
void FCFS<T>::ScheduleAlgo()
{
	Processor<T> p;
	if (p.GetStatus() == true)
	{
		AddProcess();
		ReadyList.deleteNode(p);
		RunList = p;
		p.SetStatus(false);
	}
}


template <typename T>
void FCFS<T>::AddProcess(Process* p)
{
	ReadyList.insertNode(p);
}