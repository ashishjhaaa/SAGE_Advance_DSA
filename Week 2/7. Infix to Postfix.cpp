#include <bits/stdc++.h>
using namespace std;
int precendence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' or c == '/')
    {
        return 2;
    }
    else if (c == '+' or c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPostfix(string s)
{
    stack<char>st;
    string ans;

    for (int i = 0; i < s.length();i++)
    {
        // if operand then add in answer
        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))
        {
            ans+=s[i];
        }
        // if 
        else if( s[i] =='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() and st.top()!='(')
            {
                ans += st.top();
                st.pop();
            }
        }
    }
}
int main()
{

    st.top()  // operator hai stack ke andar 
    // check that with current operator(s[i])
}