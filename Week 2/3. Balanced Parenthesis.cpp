#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' or c == '{' or c == '[')
        {
            st.push(c);
        }
        else
        {
            char top = st.top();
            if (c == ')' and top != '(') 
            {
                return false;
            }
            else if (c == '}' and top != '{')
            {
                return false;
            }
            else if(c==']' and top!='[')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cin >> s;
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced");
}