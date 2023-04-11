#include <iostream>
using namespace std;
#include "Node.h"
#include "LinkedList.cpp"


int main() {

    LinkedList<int> L1;
    L1.insertNode(37);
    L1.insertNode(38);
    L1.insertNode(39);
    L1.insertNode(40);
    L1.deleteNode(41);
    L1.insertNode(42);
    L1.insertNode(43);
    L1.deleteLastNode();
    L1.printlist();

    L1.getlistcount();


}