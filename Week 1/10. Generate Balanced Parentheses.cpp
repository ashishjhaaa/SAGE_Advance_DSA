/*
    Problem : Generate Balanced Parentheses

    Statement :
    Given n pairs of parentheses, generate all combinations of balanced
    parentheses using recursion.

    Example :
    Input  : n = 3
    Output :
             ((())) (()()) (())() ()()()
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, int n, string path)
{
    // Base case: all pairs are used
    if (open == n && close == n)
    {
        cout << path << " ";
        return;
    }

    // Recursive case:
    // 1. Add an opening bracket if possible
    if (open < n)
    {
        solve(open + 1, close, n, path + '(');
    }

    // 2. Add a closing bracket if it does not exceed opening brackets
    if (close < open)
    {
        solve(open, close + 1, n, path + ')');
    }
}

int main()
{
    int n;
    cin >> n; // Example input: 3
    solve(0, 0, n, "");
    return 0;
}

// TC: O(4^n / sqrt(n))  (Catalan number of combinations)
// SC: O(n)
