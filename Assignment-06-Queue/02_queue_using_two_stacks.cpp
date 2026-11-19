#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;

void enqueue(int value) {
    s1.push(value);
}

void dequeue() {
    if (s1.empty() && s2.empty()) {
        cout << "Queue is empty\n";
        return;
    }
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    cout << "Deleted element: " << s2.top() << endl;
    s2.pop();
}

void display() {
    stack<int> temp1 = s1;
    stack<int> temp2 = s2;

    while (!temp2.empty()) {
        cout << temp2.top() << " ";
        temp2.pop();
    }
    stack<int> temp3;
    while (!temp1.empty()) {
        temp3.push(temp1.top());
        temp1.pop();
    }
    while (!temp3.empty()) {
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(30);
    enqueue(40);

    cout << "Queue: ";
    display();

    dequeue();

    cout << "Queue after deletion: ";
    display();
    return 0;
}
