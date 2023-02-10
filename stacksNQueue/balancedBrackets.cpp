#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string expression) {
    stack<char> s;

    for (char c: expression) {
        switch(c) {
            case '(':
            case '{':
            case '[':
                      s.push(c); break;
            
            case ')': if ( !s.empty() && (s.top() == '(') ) s.pop();
                      else return false; break;
            case '}': if ( !s.empty() && (s.top() == '{') ) s.pop();
                      else return false; break;
            case ']': if ( !s.empty() && (s.top() == '[') ) s.pop();
                      else return false; break;
            
            default: continue;
        }
    }

    return true;
}

int main(void) {
    string e = "(a+b) + c(]";

    cout << (isBalanced(e) ? "Yes" : "No") << endl;

    return 0;
}