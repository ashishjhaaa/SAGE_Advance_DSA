/*
    Problem : Generate All Subsequences of a String

    Statement :
    Given a string s, print all possible subsequences
    (combinations of characters maintaining the order) using recursion.

    Example :
    Input  : s = "abc"
    Output :  c , b , bc , a , ac , ab , abc
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string s, int i, string curr)
{
    // Base case: when index reaches the end of the string
    if (i == s.length())
    {
        cout << "." << curr << endl;
        return;
    }

    // Recursive case:
    // 1. Not pick the current character
    solve(s, i + 1, curr);

    // 2. Pick the current character
    solve(s, i + 1, curr + s[i]);
}

int main()
{
    string s = "abc";
    string curr = "";
    solve(s, 0, curr);
    return 0;
}

// TC: O(2^n)
// SC: O(n)