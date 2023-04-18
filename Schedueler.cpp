#include "Schedueler.h"
#include <iostream>
#include <fstream>

using namespace std;

Schedueler::Schedueler()
{
	timestep = 0;
}


void Schedueler::load()
{
	ifstream fin("C:\\Users\\My Lap\\Downloads\\smilator\\test3.txt"); // open input file

	if (fin.fail())
	{
		std::cout << "Error opening input file\n";
	}

	// read number of processors for each scheduling algorithm
	fin >> NF >> NS >> NR;




	// read time slice for RR scheduling
	int time_slice;
	fin >> time_slice;

	// read RTF, Max, STL, and fork probability
	int RTF, Max, STL;
	double fork_prob;
	fin >> RTF >> Max >> STL >> fork_prob;

	// read number of processes
	fin >> M;


	int* arrival_times = new int[M];
	int* process_id = new int[M];
	int* cpu_time = new int[M];
	int* N = new int[M];
	int* killtimes = new int[M];
	int* IdKs = new int[M];
	int** io_times = new int* [M];




	for (int i = 0; i < M; i++) {
		fin >> arrival_times[i] >> process_id[i] >> cpu_time[i] >> N[i];

		io_times[i] = new int[N[i] * 2];
		for (int j = 0; j < N[i] * 2; j += 2) {
			char c;
			fin >> c;
			fin >> io_times[i][j] >> c >> io_times[i][j + 1]; // read io_r and io_d values
			fin >> c;
		}


		std::cout << "procces no " << i << " arrival time= " << arrival_times[i]
			<< " process_id= " << process_id[i] << " cpu_time= " << cpu_time[i] << endl;
	}

	fin.close();
	//creating the processors
	//arrP = new Processor*[NF+NS+NR];

	for (int i = 0; i < NF; i++)
	{
		arrF[i] = new FCFS();
	}

	for (int i = 0; i < NS; i++)
	{
		arrS[i] = new SJF();
	}

	for (int i = 0; i < NR; i++)
	{
		arrR[i] = new RoundRobin();
	}

	for (int i = 0; i < M; i++)
	{

		Process* p = new Process;
		newlist.enqueue(p);

		p->setarrival_time(arrival_times[i]);
		p->setprocess_id(process_id[i]);
		p->setcpu_time(cpu_time[i]);
		p->setio_requesttime(io_times[i][0]);
		p->setio_duration(io_times[i][1]);

		std::cout << "working " << i << endl;

	}

	delete[] arrival_times;
	delete[] process_id;
	delete[] cpu_time;

	for (int i = 0; i < M; i++)
	{
		delete[] io_times[i];
	}

	delete[] io_times;
	delete[] killtimes;
	delete[] IdKs;

}


void Schedueler::simulate() {
	load();
	char x;
	while (x = ' ' && TRM.getCount() != M) {
		//MOVING FROM NEWLIST TO RDY LISTS
		while (!newlist.isEmpty())
		{
			Process* p;
			newlist.peek(p);

			if (p->getarrival_time() == timestep) {
				for (int i = 0; i < NF; i++) {
					Process* data;
					newlist.dequeue(data);
					arrF[i]->AddProcessRd(data);

				}
				for (int i = 0; i < NS; i++) {
					if (!newlist.isEmpty()) {
						Process* data;
						newlist.dequeue(data);
						arrS[i]->AddProcessRd(data);
					}
				}
				for (int i = 0; i < NR; i++) {
					if (!newlist.isEmpty()) {
						Process* data;
						newlist.dequeue(data);
						arrR[i]->AddProcessRd(data);
					}
				}
			}
		}
		//if (!arrS[0]->ScheduleAlgo()->isEm) { ////////////////////////////////CHANGE IMPLEMENTATION
			//std::cout << "full before" << endl;
	}

	////MOVES FROM RDY LISTS TO RUN LISTS BASED ON STATUS
	for (int i = 0; i < NF; i++)
	{
		Process* data = arrF[i]->ScheduleAlgo();/////////////////////CHANGE IMPLEMENTATION
	}
	for (int i = 0; i < NS; i++)
	{
		Process* data = arrS[i]->ScheduleAlgo();
	}


	for (int i = 0; i < NR; i++)
	{
		Process* data = arrR[i]->ScheduleAlgo();
	}

	if (!arrS[0]->getRun())
	{
		std::cout << "full";
	}
	else
		std::cout << "empty";



	std::srand(time(0));
	//RANDOM FUNCTION MOVES FROM RUN LIST TO DIFF LISTS BASED ON NUMBER GENERATED
	for (int i = 0; i < NF; i++) {
		int numR = rand() % 100 + 1;
		if (1 <= numR && numR <= 15)
		{
			Process* p;
			p = arrF[i]->getRun();
			Blk.enqueue(p);

		}
		if (20 <= numR && numR <= 30) {
			//arrF[i].getReadyList().insertNode(arrF[i].getRun().dequeue());

		}
		if (50 <= numR && numR <= 60) {

			Process* p;
			p = arrF[i]->getRun();
			TRM.enqueue(p);
		}
	}
	for (int i = 0; i < NS; i++) {

		int numR = rand() % 100 + 1;
		if (1 <= numR && numR <= 15)
		{
			Process* p;
			p = arrS[i]->getRun();
			Blk.enqueue(p);
		}
		if (20 <= numR && numR <= 30) {
			//arrS[i].getReadyList().insert(arrS[i].getRun().dequeue(), arrS[i].getRun().dequeue().getcpu_time());

		}
		if (50 <= numR && numR <= 60) {

			Process* p;
			p = arrS[i]->getRun();
			TRM.enqueue(p);

		}
	}
	for (int i = 0; i < NR; i++) {

		int numR = rand() % 100 + 1;
		if (1 <= numR && numR <= 15)
		{
			Process* p;
			p = arrR[i]->getRun();
			Blk.enqueue(p);

		}
		if (20 <= numR && numR <= 30) {
			//arrR[i].getReadyList().enqueue(arrR[i].getRun().dequeue());

		}
		if (50 <= numR && numR <= 60) {
			Process* p;
			p = arrR[i]->getRun();
			TRM.enqueue(p);
		}
	}
	int numrb = rand() % 100 + 1;
	if (numrb <= 10)
	{
		Process* p;
		Blk.dequeue(p);
	}
	int numF = rand() % NF;

	//for (int i = 0; i < NF; i++)
	//{
	//    if (!arrF[i].getReadyList().isempty()) {
	//        if (arrF[i].getReadyList().getdata().getprocess_id() == numF) {
	//            TRM.enqueue(arrF[i].getReadyList().getdata());
	//            arrF[i].getReadyList().deleteNode();
	//}

	/*timestep++;
	std::cout << "PRESS ENTER TO CONTINUE";
	cin >> x;*/
}










