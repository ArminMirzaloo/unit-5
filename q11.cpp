#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueUsingTwoStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl;  

    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl;  
    cout << "Dequeued: " << q.dequeue() << endl;  

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    return 0;
}
