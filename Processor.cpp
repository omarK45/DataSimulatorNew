#include "Processor.h"


Processor::Processor()
{

}



void Processor::SetStatus(bool s)
{
	status = s;  //TRUE=IDLE FALSE=BUSY
}


bool Processor::GetStatus()
{
	return status;
}



int Processor::PLoad()
{
	return busytime;
}



int Processor::PUtil()
{
	return busytime;
}

