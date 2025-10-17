#include <bits/stdc++.h>
using namespace std;
int prefixEvaluator(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        // case 1 -- operand ---   0 to 9
        if (s[i] >= '0' and s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        // case 2 -- operator   --   +, -, *, /
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            default:
                cout << "Enter correct operator " << endl;
                return -1;
            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    int ans = prefixEvaluator(s);
    if(ans==-1)
    {
        cout << "invalid";
    }
    else
    {
        cout << ans << endl;
    }
}


// Prefix Evaluation - done
// Postfix Evaluation - done
// Infix to Postfix - doing
// Infix to Prefix 