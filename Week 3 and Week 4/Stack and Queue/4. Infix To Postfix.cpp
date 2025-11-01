#include <bits/stdc++.h>
using namespace std;

// get precedence of operators
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

// convert infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string result = "";

    for (char c : s)
    {
        // if operand, add to result
        if (isalnum(c))
            result += c;

        // if '(', push to stack
        else if (c == '(')
            st.push(c);

        // if ')', pop till '('
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // if operator
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                if (c == '^' && st.top() == '^')
                    break; // handle right associativity
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string infix = "(A+B)*C-D";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
