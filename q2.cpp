#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<int> findCommonElements(stack<int> s, queue<int> q) {
    vector<int> commonElements;

    while (!s.empty()) {
        int stackElement = s.top();
        s.pop();

        queue<int> tempQueue = q;  

        while (!tempQueue.empty()) {
            int queueElement = tempQueue.front();
            tempQueue.pop();

            if (stackElement == queueElement) {
                commonElements.push_back(stackElement);
                break;
            }
        }
    }

    return commonElements;
}

int main() {
    stack<int> s;
    queue<int> q;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> result = findCommonElements(s, q);

    cout << "Common elements: ";
    for (int element : result) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
