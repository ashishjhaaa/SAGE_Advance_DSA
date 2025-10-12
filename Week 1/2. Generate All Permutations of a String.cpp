/*
    Problem : Generate All Permutations of a String

    Statement :
    Given a string s, print all possible permutations of the string using recursion.
    Each permutation represents a unique arrangement of the characters.

    Example :
    Input  : s = "123"
    Output :
             123
             132
             213
             231
             312
             321
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string s, int l, int r)
{
    // Base case: when left index equals right index, print the permutation
    if (l == r)
    {
        cout << s << endl;
        return;
    }

    // Recursive case: generate all permutations by swapping each character
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);   // Fix one character
        solve(s, l + 1, r); // Recur for the remaining substring
        swap(s[l], s[i]);   // Backtrack to restore original string
    }
}

int main()
{
    string s;
    cin >> s;
    solve(s, 0, s.size() - 1);
    return 0;
}

// TC: O(n * n!)
// SC: O(n)