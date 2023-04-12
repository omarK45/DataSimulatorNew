#include <iostream>
using namespace std;
#include "Node.h"
#include "LinkedList.cpp"
#include"Stack.cpp"


int main() {

    //LinkedList<int> L1;
    //L1.insertNode(37);
    //L1.insertNode(38);
    //L1.insertNode(39);
    //L1.insertNode(40);
    //L1.deleteNode(38);
    //L1.printlist();
    Stack<int> s1;
    int item;
    for (int i = 0; i < 3; i++) {
        cout << "enter item to push\n";
        cin >> item;
        s1.push(item);
        s1.display();

    }
    cout << s1.pop() << " " << "was deleted from stack\n";
    s1.display();
    cout << s1.pop() << " " << "was deleted from stack\n";
    s1.display();
    cout << s1.count() ;
}