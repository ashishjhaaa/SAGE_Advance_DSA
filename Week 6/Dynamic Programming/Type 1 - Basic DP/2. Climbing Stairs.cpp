/******************************************************
Problem Statement: Climbing Stairs

You are given an integer n.
You can climb either 1 step or 2 steps at a time.
Return the total number of distinct ways to reach the top.

Test Case 1:
Input: 2

Test Case 2:
Input: 3

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
We have two choices at every step:
→ Climb 1 step: solve(n-1)
→ Climb 2 steps: solve(n-2)

So total ways = ways(n-1) + ways(n-2)

This leads to exponential time because the same
subproblems are recomputed several times.
----------------------------------------------------*/

int climbRecursion(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    // Two choices: take 1 step or take 2 steps
    return climbRecursion(n - 1) + climbRecursion(n - 2);
}

/*----------------------------------------------------
2. Memoization (Top-Down DP)
------------------------------------------------------
Overlapping Subproblems:
ways(5) → ways(4) & ways(3)
ways(4) → ways(3) & ways(2)
ways(3) → ways(2) & ways(1)
→ ways(3), ways(2) computed multiple times.

Use dp[n] to store results and avoid recomputation.
----------------------------------------------------*/

int memoHelper(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = memoHelper(n - 1, dp) + memoHelper(n - 2, dp);
    return dp[n];
}

int climbMemoization(int n)
{
    vector<int> dp(n + 1, -1);
    return memoHelper(n, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
We build dp[] from the base:
dp[0] = 1
dp[1] = 1

Each state: dp[i] = dp[i-1] + dp[i-2]
----------------------------------------------------*/

int climbTabulation(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
We only need previous two states:
prev2 → ways(i-2)
prev1 → ways(i-1)
curr → prev1 + prev2
----------------------------------------------------*/

int climbSpaceOptimized(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int prev2 = 1;
    int prev1 = 1;
    int curr = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    cout << "Using Recursion: " << climbRecursion(n) << endl;
    cout << "Using Memoization: " << climbMemoization(n) << endl;
    cout << "Using Tabulation: " << climbTabulation(n) << endl;
    cout << "Using Space Optimized: " << climbSpaceOptimized(n) << endl;

    return 0;
}