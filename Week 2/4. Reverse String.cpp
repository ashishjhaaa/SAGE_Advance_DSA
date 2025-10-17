#include<bits/stdc++.h>
using namespace std;
string reverseString(string s)
{
    stack<char> st;
    for(char c: s)
    {
        st.push(c);
    }

    string ans;

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string s = "Hello";
    cout << reverseString(s) << endl;
}

// Stack/Queues using Array 
// Monotonic Stack // next greater/smaller element
// Queue Problem 