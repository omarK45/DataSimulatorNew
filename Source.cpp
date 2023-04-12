#include <iostream>
using namespace std;
#include "Node.h"
#include "LinkedList.cpp"
#include "Queue.cpp"
#include "stack.cpp"


int main() {
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
    cout << s1.count();
}
