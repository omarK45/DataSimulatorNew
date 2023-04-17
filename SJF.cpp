#include "SJF.h"

template <typename T>
void SJF<T>::ScheduleAlgo()
{
	Processor p;
	if (p.GetStatus() == true)
	{
		AddProcessRd();
		p.SetStatus(false);
	}
}


template <typename T>
void SJF<T>::AddProcessRd(Process* p)
{
	ReadyList.insert(p, priority);
}

template<class T>
void SJF<T>::AddProcessRn(Process* p)
{
	RunList.enqueue(p);
}

template <class T>
Queue<T>& SJF<T>::getReadyList()
{
	return ReadyList;
}

template<class T>
Queue<T>& SJF<T>::getRun()
{
	return RunList;
}
