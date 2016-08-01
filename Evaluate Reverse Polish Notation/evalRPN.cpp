#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) 
{
    stack<int> s;

    for (string opr : tokens)
    {
        if (opr == "+" || opr == "-" || opr == "*" || opr == "/")
        {
            int b = s.top();
            s.pop();
            int a  = s.top();
            s.pop();
            switch(opr[0])
            {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                default:
                    break;
            }
        }
        else
        {
            s.push(stoi(opr));
        }
    }
    
    return s.top();
}