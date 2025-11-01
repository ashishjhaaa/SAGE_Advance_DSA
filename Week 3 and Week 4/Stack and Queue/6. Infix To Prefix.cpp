#include <bits/stdc++.h>
using namespace std;

// precedence for operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// function to convert infix to prefix
string infixToPrefix(string s)
{
    // reverse the infix expression
    reverse(s.begin(), s.end());

    // swap '(' and ')'
    for (auto &ch : s)
    {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    stack<char> st;
    string result = "";

    for (char c : s)
    {
        if (isalnum(c))
            result += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        { // operator
            while (!st.empty() && precedence(c) < precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    // reverse final result
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string infix = "(A+B)*C-D";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}
