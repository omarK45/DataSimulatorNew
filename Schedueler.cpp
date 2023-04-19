#include "Schedueler.h"
#include "UI.h"
#include <iostream>
#include <fstream>

using namespace std;

Schedueler::Schedueler()
{
	timestep = 0;
	
}


void Schedueler::load()
{
	ifstream fin("C:\\Users\\Lenovo\\Desktop\\SENTCHANGE\\test3.txt"); // open input file

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
	arrF = new FCFS[NF];
	arrP = new Processor * [NF + NS + NR];
	for (int i = 0; i < NF; i++) {
		arrF[i] = FCFS();
		arrP[i] = &arrF[i];
	}
	arrS = new SJF[NS];
	for (int i = 0; i < NS; i++) {
		arrS[i] = SJF();
		arrP[NF + i] = &arrS[i];
	}
	arrR = new RoundRobin[NR];
	for (int i = 0; i < NR; i++) {
		arrR[i] = RoundRobin();
		arrP[NF + NS + i] = &arrR[i];
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

		cout << "working " << i << endl;

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


void Schedueler::simulate()
{
	load();
	while (TRM.getCount() != M) {
		char x;
		if (!newlist.isEmpty()) {

			cout << "working and count is= " << newlist.getCount() << endl;
		}
		int c = newlist.getCount();
		//MOVING FROM NEWLIST TO RDY LISTS
		if (!newlist.isEmpty())

			for (int i = 0; i < c; i++) {

				Process* p = newlist.dequeue();
				arrP[i]->AddProcessRd(p);
			}
		if (newlist.isEmpty()) {
			cout << "NEWLIST IS EMPTY" << endl;
		}
		if (!arrP[0]->Empty()) {
			cout << "ready is not empty before" << endl;
		}
		////MOVES FROM RDY LISTS TO RUN LISTS BASED ON STATUS
		for (int i = 0; i < NF + NS + NR; i++) {
			if (arrP[i]->ScheduleAlgo() == NULL) {
				break;
			};
			arrP[i]->ScheduleAlgo();

		}
		if (!arrP[0]->Empty()) {
			cout << "ready is empty after" << endl;
		}
		srand(time(0));

		//RANDOM FUNCTION MOVES FROM RUN LIST TO DIFF LISTS BASED ON NUMBER GENERATED
		for (int i = 0; i < NF + NS + NR; i++) {
			while (arrP[i]->getRun() != NULL && !arrP[i]->Empty()) {
				int numR = (rand() % 100) + 1;
				cout << "Rand is =" << numR << endl;
				if (numR >= 1 && numR <= 15) {

					Blk.enqueue(arrP[i]->getRun());
				}

				if (numR >= 20 && numR <= 30) {

					arrP[i]->AddProcessRd(arrP[i]->getRun());
					if (!arrP[i]->Empty()) {
						cout << "Ready is Not Empty" << endl;
					}

				}
				if (numR >= 50 && numR <= 60) {

					TRM.enqueue(arrP[i]->getRun());
				}
			}
		}
		if (!Blk.isEmpty()) {

			cout << "blk is not empty" << endl;
		}
		if (!TRM.isEmpty()) {

			cout << "TRM is not empty" << endl;
		}
	}
	Process* *run;
	for (int i = 0; i < n; i++) {
		run[i] = arrP[i]->getRun();
		{
			cin.ignore();
		}








	}
	}
