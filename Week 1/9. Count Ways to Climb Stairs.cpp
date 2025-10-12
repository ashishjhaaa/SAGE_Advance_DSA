
/*
    Problem : Count Ways to Climb Stairs

    Statement :
    A person can climb either 1 or 2 steps at a time. Given n steps,
    calculate the total number of distinct ways to reach the top using recursion.

    Example :
    Input  : n = 5
    Output : 8

    Explanation :
    There are 8 different sequences to climb 5 steps using 1-step and 2-step moves.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    // Base case: if no steps left, count as 1 way
    if (n == 0)
    {
        return 1;
    }

    // Base case: negative steps, invalid path
    if (n < 0)
    {
        return 0;
    }

    // Recursive case: take 1 step or 2 steps
    return solve(n - 1) + solve(n - 2);
}

int main()
{
    int n;
    cin >> n; // Example input: 5

    cout << solve(n) << endl;

    return 0;
}

// TC: O(2^n)
// SC: O(n)
