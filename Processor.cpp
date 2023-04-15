#include "Processor.h"

template <typename T>
Processor<T>::Processor()
{
	ReadyList.isempty() = true;
}


//processor state
template <typename T>
void Processor<T>::SetStatus()
{
	if (ReadyList.isempty())
		status = true;
	else
		status = false;
}


template <typename T>
bool Processor<T>::GetStatus()
{
	return status;
}


template <typename T>
int Processor<T>::PLoad()
{
	return busytime;
}


template <typename T>
int Processor<T>::PUtil()
{
	return busytime;
}