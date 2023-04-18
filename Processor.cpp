#include "Processor.h"


#include "Processor.h"


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
void Processor::printRDY() {
    RDY.printQueue();
}
string Processor::return_Type() {
    return Type;
}
