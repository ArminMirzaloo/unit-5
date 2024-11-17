#include <iostream>
#include <stack>

using namespace std;

int evaluatePrefix(string expression) {
    stack<int> s;

    for (int i = expression.length() - 1; i >= 0; i--) {
        char c = expression[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand1 = s.top(); s.pop();
            int operand2 = s.top(); s.pop();

            int result;
            if (c == '+') result = operand1 + operand2;
            else if (c == '-') result = operand1 - operand2;
            else if (c == '*') result = operand1 * operand2;
            else if (c == '/') result = operand1 / operand2;

            s.push(result);
        }
    }

    return s.top();
}

int main() {
    string expression = "*+37-56";
    int result = evaluatePrefix(expression);
    cout << result << endl;
    return 0;
}
