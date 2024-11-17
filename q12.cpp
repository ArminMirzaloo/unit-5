#include <iostream>
#include <queue>

using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedValue = q1.front();
        q1.pop();
        swap(q1, q2);

        return poppedValue;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topValue = q1.front();
        q2.push(topValue);
        swap(q1, q2);

        return topValue;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues stack;

    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << "Top element: " << stack.top() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    stack.push(7);
    stack.push(8);
    cout << "Top element: " << stack.top() << endl;

    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
