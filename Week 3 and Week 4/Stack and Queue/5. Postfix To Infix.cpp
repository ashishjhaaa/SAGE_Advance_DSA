#include <bits/stdc++.h>
using namespace std;

// helper to check if character is operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// convert postfix to infix
string postfixToInfix(string postfix)
{
    stack<string> st;

    for (char ch : postfix)
    {
        if (isOperator(ch))
        {
            // pop two operands
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            // form infix expression: (op1 operator op2)
            string temp = "(" + op1 + ch + op2 + ")";
            st.push(temp);
        }
        else
        {
            // push operand as string
            st.push(string(1, ch));
        }
    }
    return st.top();
}

int main()
{
    string postfix = "AB+C*D-";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfixToInfix(postfix) << endl;
    return 0;
}
