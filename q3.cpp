#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverseStack(stack<int> &s) {
    queue<int> q;

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(4);
    s.push(8);
    s.push(16);

    cout << "Stack before reversing: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "Stack after reversing: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
