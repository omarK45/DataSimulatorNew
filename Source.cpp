#include <iostream>
using namespace std;
#include "Node.h"
#include "LinkedList.cpp"
#include "Queue.cpp"


int main() {
    Queue<int> q1;
    q1.enqueue(5);
    q1.enqueue(3);
    q1.enqueue(8);
    q1.enqueue(4);
    q1.dequeue();
    q1.printQueue();
    int x = q1.peek();
    cout << "peek=" << x;
    return 0;

}