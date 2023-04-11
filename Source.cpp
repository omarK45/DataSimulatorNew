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
    L1.deleteNode(38);
    L1.printlist();


}