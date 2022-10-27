#include <stack>
#include <string>
#include <iostream>

using namespace std;

int priority(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        case '(': return 0;
    }
    return -1;
}

string inToPost(string expr) {
    stack<char> s; char ch,topToken,tokenOut;
    string expr2 = "";
    s.push('#');
    for (int i=0;i<expr.length();i++) {
        if (expr.at(i)=='(') {
            s.push(expr.at(i));
        } else if (expr.at(i)==')') {
            ch = s.top();
            s.pop();
            while (ch!='(') {
                expr2.push_back(ch);
                ch = s.top();
                s.pop();
            }
        } else if (expr.at(i)=='^'||expr.at(i)=='*'||expr.at(i)=='/'||expr.at(i)=='+'||expr.at(i)=='-') {
            topToken = s.top();
            while (s.top()!='#' && priority(expr.at(i))<=priority(topToken)) {
                tokenOut = s.top();
                s.pop();
                expr2.push_back(tokenOut);
                topToken = s.top();
            }
            s.push(expr[i]);
        } else {
            expr2.push_back(expr.at(i));
        }
    }
    while (s.top()!='#') {
        expr2.push_back(s.top());
        s.pop();
    }
    return expr2;
}

int main() {
    string expr;
    cout<<"Enter valid infix expression: ";
    getline(cin,expr);
    expr = inToPost(expr);
    cout<<"Equivalent postfix expression: "<<expr;
    return 0;
}