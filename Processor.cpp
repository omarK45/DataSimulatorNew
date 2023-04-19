#include "Processor.h"


Processor::Processor()
{
	status = true;
	Rd = false;
}

bool Processor::Empty() {
	return Rd;
}



void Processor::SetStatus(bool s)
{
	status = s;  //TRUE=IDLE FALSE=BUSY
}
string Processor::return_Type() {
	return Type;
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

