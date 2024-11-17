#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string &input) {
    stack<char> s;

    for (char ch : input) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) {
                cout << "unbalanced" << endl;
                return false;
            }
            s.pop();
        }
    }

    if (s.empty()) {
        cout << "balanced" << endl;
        return true;
    } else {
        cout << "unbalanced" << endl;
        return false;
    }
}

int main() {
    string input;
    cout << "Enter a string with parentheses: ";
    cin >> input;

    isBalanced(input);

    return 0;
}
