#include "Schedueler.h"
#include <iostream>
#include <fstream>
using namespace std;

Schedueler::Schedueler() {


    timestep = 3;
    x = ' ';
}


void Schedueler::load() {
    ifstream fin("C:\\Users\\Lenovo\\Desktop\\Datastackadd\\test3.txt"); // open input file
    if (fin.fail()) {
        cout << "Error opening input file\n";

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


        cout << "procces no " << i << " arrival time= " << arrival_times[i]
            << " process_id= " << process_id[i] << " cpu_time= " << cpu_time[i] << endl;
    }

    fin.close();
    //creating the processors
    arrP = new Processor*[NF+NS+NR];

    arrF = new FCFS[NF];
    for (int i = 0; i < NF; i++) {

        FCFS F;
        arrF[i] = F;
        arrP[i] = &F;

    }

    arrS = new SJF[NS];
    for (int i = 0; i < NS; i++) {

        SJF S;
        arrS[i] = S;
        arrP[NF + i] = &S;

    }
    arrR = new RoundRobin[NR];
    for (int i = 0; i < NR; i++) {
        RoundRobin R;
        arrR[i] = R;
        arrP[NF +NS+ i] = &R;
    }
    for (int i = 0; i < M; i++)
    {

        Process p;
        p.setarrival_time(arrival_times[i]);
        p.setprocess_id(process_id[i]);
        p.setcpu_time(cpu_time[i]);
        p.setio_requesttime(io_times[i][0]);
        p.setio_duration(io_times[i][1]);
        newlist.enqueue(p);
        cout << "working " << i<<endl;

    }
   
    delete[] arrival_times;
    delete[] process_id;
    delete[] cpu_time;
    for (int i = 0; i < M; i++) {
        delete[] io_times[i];
    }
    delete[] io_times;
    delete[] killtimes;
    delete[] IdKs;

}


void Schedueler::simulate() {
    load();
    while (x=' ' && TRM.getcount() != M) {
        while (!newlist.isEmpty())
            //MOVING FROM NEWLIST TO RDY LISTS
        while (!newlist.isEmpty()) {
            if (newlist.peek().getarrival_time() == timestep) {
                for (int i = 0; i < NF; i++) {
                    Process data = newlist.dequeue();
                    arrF[i].AddProcessRd(data);

                }
                for (int i = 0; i < NS; i++) {
                    if (!newlist.isEmpty()) {
                        Process data = newlist.dequeue();;
                        arrS[i].AddProcessRd(data);
                    }
                }
                for (int i = 0; i < NR; i++) {
                    if (!newlist.isEmpty()) {
                        Process data = newlist.dequeue();
                        arrR[i].AddProcessRd(data);
                    }
                }
            }
        }
        if (!arrS[0].getReadyList().isEmpty()) {
            cout << "full before" << endl;
        }

        //MOVES FROM RDY LISTS TO RUN LISTS BASED ON STATUS
        for (int i = 0; i < NF; i++)
        {
            if (arrF[i].GetStatus()) {

                Process data = arrF[i].getReadyList().getdata();
                arrF[i].getReadyList().deleteNode();
                arrF[i].AddProcessRn(data);
            }
        }
        for (int i = 0; i < NS; i++)
        {
            if (!arrS[i].getReadyList().isEmpty())
                if (arrS[i].GetStatus()) {
                    Process data = arrS[i].getReadyList().remove();
                    arrS[i].AddProcessRn(data);
                }
        }

        for (int i = 0; i < NR; i++)
        {
            if (!arrS[i].getReadyList().isEmpty()) {
                if (arrR[i].GetStatus()) {
                    Process data = arrR[i].getReadyList().dequeue();
                    arrR[i].AddProcessRn(data);
                }
            }
        }
        if (!arrS[0].getRun().isEmpty()) {
            cout << "full";
        }
        else
            cout << "empty";



        srand(timestep);
        //RANDOM FUNCTION MOVES FROM RUN LIST TO DIFF LISTS BASED ON NUMBER GENERATED
        for (int i = 0; i < NF; i++) {
            int numR = rand() % 100 + 1;
            if (1 <= numR && numR <= 15) {
                Blk.enqueue(arrF[i].getRun().dequeue());

            }
            if (20 <= numR && numR <= 30) {
                arrF[i].getReadyList().insertNode(arrF[i].getRun().dequeue());

            }
            if (50 <= numR && numR <= 60) {

                TRM.enqueue(arrF[i].getRun().dequeue());
            }
        }
        for (int i = 0; i < NS; i++) {

            int numR = rand() % 100 + 1;
            if (1 <= numR && numR <= 15) {
                Blk.enqueue(arrS[i].getRun().dequeue());

            }
            if (20 <= numR && numR <= 30) {
                arrS[i].getReadyList().insert(arrS[i].getRun().dequeue(), arrS[i].getRun().dequeue().getcpu_time());

            }
            if (50 <= numR && numR <= 60) {

                TRM.enqueue(arrS[i].getRun().dequeue());

            }
        }
        for (int i = 0; i < NR; i++) {

            int numR = rand() % 100 + 1;
            if (1 <= numR && numR <= 15) {
                Blk.enqueue(arrR[i].getRun().dequeue());

            }
            if (20 <= numR && numR <= 30) {
                arrR[i].getReadyList().enqueue(arrR[i].getRun().dequeue());

            }
            if (50 <= numR && numR <= 60) {

                TRM.enqueue(arrR[i].getRun().dequeue());
            }
        }
        int numrb = rand() % 100 + 1;
        if (numrb <= 10) {
            Blk.dequeue();
        }
        int numF = rand() % NF;
        for (int i = 0; i < NF; i++) {
            if (!arrF[i].getReadyList().isempty()) {
                if (arrF[i].getReadyList().getdata().getprocess_id() == numF) {
                    TRM.enqueue(arrF[i].getReadyList().getdata());
                    arrF[i].getReadyList().deleteNode();
                }
            }

        }

        timestep++;
        cout << "PRESS ENTER TO CONTINUE";
        cin >> x;
       
    }
}






  



