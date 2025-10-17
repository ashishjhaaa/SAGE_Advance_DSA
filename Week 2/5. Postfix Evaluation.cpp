#include <bits/stdc++.h>
using namespace std;
int postfixEvaluator(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            case '^':
                st.push(pow(operand1, operand2));
                break;
            default:
                cout << "Enter corrrect operator " << endl;
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
    int ans = postfixEvaluator(s);
    if (ans == -1)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}