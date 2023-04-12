#include "Schedueler.h"
#include <iostream>
#include <fstream>
using namespace std;
Schedueler::Schedueler() {




}
int load() {
    ifstream fin("C:\\Users\\Lenovo\\Desktop\\Datastackadd\\test2.txt"); // open input file
    if (fin.fail()) {
        cout << "Error opening input file\n";
        return 1;
    }

    // read number of processors for each scheduling algorithm
    int NF, NS, NR;
    fin >> NF >> NS >> NR;

    // read time slice for RR scheduling
    int time_slice;
    fin >> time_slice;

    // read RTF, Max, STL, and fork probability
    int RTF, Max, STL;
    double fork_prob;
    fin >> RTF >> Max >> STL >> fork_prob;

    // read number of processes
    int M;
    fin >> M;
    cout << "no of nf ns nr " << NF << NS << NR << endl;
    cout << "time slice rr " << time_slice << endl;
    cout << "RTF Max STL Fork" << " " << RTF << " " << Max << " " << STL << " " << fork_prob << endl;
    cout << "no of nf ns nr " << NF << NS << NR << endl;
    cout << "no of processes= " << M << endl;

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
            << " process_id= " << process_id[i] << " cpu_time= " << cpu_time[i];

        cout << " io_times= ";
        for (int j = 0; j < N[i] * 2; j += 2) {
            cout << "(" << io_times[i][j] << "," << io_times[i][j + 1] << ")";
        }
        cout << endl;
    }
    int c = 0;
    while (fin >> killtimes[c] >> IdKs[c]) {
        cout << "kill process id= " << IdKs[c] << " at time= " << killtimes[c] << endl;
        c++;
    }

    fin.close();

    delete[] arrival_times;
    delete[] process_id;
    delete[] cpu_time;
    for (int i = 0; i < M; i++) {
        delete[] io_times[i];
    }
    delete[] io_times;
    delete[] killtimes;
    delete[] IdKs;
    return 0;
}

