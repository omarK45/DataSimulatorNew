#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("C:\\Users\\zizor\\OneDrive\\Desktop\\trial\\tacos.txt"); // open input file
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

    // allocate arrays for process information
    int* arrival_times = new int[M];
    int* burst_times = new int[M];
    int* priorities = new int[M];
    int* *io_times = new int*[M];

    // read information for each process
    for (int i = 0; i < M; i++) {
        fin >> arrival_times[i] >> burst_times[i] >> priorities[i];
        io_times[i] = new int[2];
        fin >> io_times[i][0] >> io_times[i][1];
    }

    fin.close(); 
   
    delete[] arrival_times;
    delete[] burst_times;
    delete[] priorities;
    for (int i = 0; i < M; i++) {
        delete[] io_times[i]; 
    }
    delete[] io_times;

    return 0;
}
