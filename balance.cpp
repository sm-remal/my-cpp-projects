// Syntax Analysis - Balance

#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool isBalanced(const std::string &expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is NOT balanced." << endl;
    }

    return 0;
}






