#include "UI.h"
void UI::print(Processor *p[], int numprocessor, Queue<Process>*blk, Queue<Process>*run, Queue<Process>*trm,int timestep) {
cout<<"current Timestep:"<<timestep<<endl;
cout<<"-----------------   RDY processes __________________________"<<endl;
for(int i=0;i<numprocessor;i++){
    cout<<"processor  "<<i+1<<"  ["<<p[i]->return_Type()<<"]"<<": "<<"RDY";
    p[i]->printRDY();

    cout<<endl;
}
    cout<<"-----------------   BLK processes __________________________"<<endl;
cout<<blk->getcount()<<" BLK: ";
blk->printQueue();
cout<<endl;
cout<<"-----------------   RUN processes __________________________"<<endl;
cout<<run->getcount()<<" RUN: ";
run->printQueue();
cout<<endl;  cout<<"-----------------   TRM processes __________________________"<<endl;
cout<<trm->getcount()<<" BLK: ";
trm->printQueue();
cout<<endl;
}