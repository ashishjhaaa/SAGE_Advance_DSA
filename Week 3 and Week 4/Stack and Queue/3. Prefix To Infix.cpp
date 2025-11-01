#include <bits/stdc++.h>
using namespace std;

// helper: check if character is operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// convert prefix to infix
string prefixToInfix(string prefix)
{
    stack<string> st;

    // traverse from right to left
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isOperator(ch))
        {
            // pop two operands
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            // form expression: (op1 operator op2)
            string temp = "(" + op1 + ch + op2 + ")";
            st.push(temp);
        }
        else
        {
            // push operand as string
            st.push(string(1, ch));
        }
    }

    return st.top(); // final infix expression
}

int main()
{
    string prefix = "*+AB-CD";
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefixToInfix(prefix) << endl;
    return 0;
}
