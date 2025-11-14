/******************************************************
Problem Statement: Fibonacci Number

Given a number n, return the nth Fibonacci number.
The Fibonacci sequence is:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

Test Case 1:
Input: 5

Test Case 2:
Input: 10
******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
We have two choices:
→ Either take F(n-1)
→ Or take F(n-2)
And add them.

This leads to exponential time because the same
subproblems are recomputed many times.
----------------------------------------------------*/

int fibRecursion(int n)
{
    if (n <= 1)
    {
        return n;
    }

    // Two choices: take previous OR second previous
    return fibRecursion(n - 1) + fibRecursion(n - 2);
}

/*----------------------------------------------------
2. Memoization (Top-Down DP)
------------------------------------------------------
Overlapping Subproblems:
F(n) requires F(n-1) and F(n-2).
Both again recursively call lower Fibonacci numbers.
Example:
F(5) calls F(4) and F(3)
F(4) again calls F(3) and F(2)
F(3) again calls F(2) and F(1)
→ F(3), F(2) calculated many times.

To avoid recomputation, store results in dp.
----------------------------------------------------*/

int fibMemoHelper(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibMemoHelper(n - 1, dp) + fibMemoHelper(n - 2, dp);
    return dp[n];
}

int fibMemoization(int n)
{
    vector<int> dp(n + 1, -1);
    return fibMemoHelper(n, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
We fill dp array starting from base cases:
dp[0] = 0
dp[1] = 1

Then compute dp[i] = dp[i-1] + dp[i-2]
----------------------------------------------------*/

int fibTabulation(int n)
{
    if (n <= 1)
    {
        return n;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
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
Instead of keeping an array, we only need last two values:
prev2 → F(n-2)
prev1 → F(n-1)

curr = prev1 + prev2
Shift window on each iteration.
----------------------------------------------------*/

int fibSpaceOptimized(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int prev2 = 0;
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
    cout << "Enter n: ";
    cin >> n;

    cout << endl;
    cout << "Using Recursion: " << fibRecursion(n) << endl;
    cout << "Using Memoization: " << fibMemoization(n) << endl;
    cout << "Using Tabulation: " << fibTabulation(n) << endl;
    cout << "Using Space Optimized: " << fibSpaceOptimized(n) << endl;

    return 0;
}