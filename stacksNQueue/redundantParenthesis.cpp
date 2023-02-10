#include <iostream>
#include <stack>

using namespace std;

bool isRedundant(string expression) {
    stack<char> s;

    for (char c: expression) {
        if (c != ')') {
            s.push(c);
        }
        else {
            bool operator_found = false;
            while ( !s.empty() && (s.top() != '(') ) {
                char top = s.top();
                if (top == '+' || top == '-' || top == '/' || top == '*') {
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();
            if (!operator_found) {
                return true;
            }
        }
    }
    
    if (!s.empty()) return true;
    
    return false;
}

int main(void) {
    string s = "(((a+b)+c))";

    cout << (isRedundant(s) ? "Redundant" : "Not Redundant") << endl;

    return 0;
}