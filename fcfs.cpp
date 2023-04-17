#include "FCFS.h"
template <typename T>
FCFS<T>::FCFS() {



}
template <typename T>
void FCFS<T>::ScheduleAlgo()
{
	Processor p;
	if (p.GetStatus() == true)
	{
		AddProcessRd();
		ReadyList.deleteNode(p);
		p.SetStatus(false);
	}
}


template <typename T>
void FCFS<T>::AddProcessRd(Process* p)
{
	ReadyList.insertNode(p);
}

template<class T>
void FCFS<T>::AddProcessRn(Process* p)
{
	RunList.enqueue(p);
}

template <class T>
LinkedList<T>& FCFS<T>::getReadyList()
{
	return ReadyList;
}

template<class T>
Queue<T>& FCFS<T>::getRun()
{
	return RunList;
}


