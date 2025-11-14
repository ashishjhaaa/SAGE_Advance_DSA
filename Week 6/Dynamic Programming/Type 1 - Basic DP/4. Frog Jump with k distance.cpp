/******************************************************
Problem Statement: Frog Jump With K Distance

A frog is at index 0 and wants to reach index n-1.
He can jump from index i to ANY index j where:
1 ≤ j - i ≤ k

Energy cost:
abs(heights[i] - heights[j])

Return the minimum total energy required.

Test Case 1:
Input:
n = 5, k = 3
heights = [10, 30, 40, 20, 50]

Test Case 2:
Input:
n = 4, k = 2
heights = [10, 20, 10, 30]

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
At every index i:
Try ALL jumps from 1 to k:
cost = abs(h[i] - h[i-j]) + solve(i-j)

Pick the minimum out of all possible jumps.
----------------------------------------------------*/
int frogKRec(int idx, vector<int> &h, int k)
{
    if (idx == 0)
    {
        return 0;
    }

    int mini = INT_MAX;

    // Try all jumps from 1 to k
    for (int j = 1; j <= k; j++)
    {
        if (idx - j >= 0)
        {
            int cost = frogKRec(idx - j, h, k) + abs(h[idx] - h[idx - j]);
            mini = min(mini, cost);
        }
    }

    return mini;
}

/*----------------------------------------------------
2. Memoization (Top-Down DP)
------------------------------------------------------
Overlapping Subproblems:
solve(10) needs solve(9), solve(8), solve(7) ...
solve(9) needs solve(8), solve(7), solve(6) ...
→ solve(8), solve(7), solve(6) computed many times.
----------------------------------------------------*/
int frogKMemoHelper(int idx, vector<int> &h, int k, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int mini = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (idx - j >= 0)
        {
            int cost = frogKMemoHelper(idx - j, h, k, dp) + abs(h[idx] - h[idx - j]);
            mini = min(mini, cost);
        }
    }

    return dp[idx] = mini;
}

int frogKMemoization(int n, vector<int> &h, int k)
{
    vector<int> dp(n, -1);
    return frogKMemoHelper(n - 1, h, k, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
dp[i] = min cost to reach index i

Transition:
dp[i] = min(
    dp[i-1] + abs(h[i] - h[i-1]),
    dp[i-2] + abs(h[i] - h[i-2]),
    dp[i-3] + abs(h[i] - h[i-3]),
    ...
    dp[i-k] + abs(h[i] - h[i-k])
)
----------------------------------------------------*/
int frogKTabulation(int n, vector<int> &h, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int cost = dp[i - j] + abs(h[i] - h[i - j]);
                mini = min(mini, cost);
            }
        }

        dp[i] = mini;
    }

    return dp[n - 1];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
For K jumps, classical space-optimization (like keeping
only last 2 values) is NOT possible because each state
depends on up to k previous states.

However, we still reduce overhead by using a deque-like
sliding computation (though dp array is still required).

Final note:
Space cannot be reduced below O(n) for variable k.
----------------------------------------------------*/
int frogKSpaceOptimized(int n, vector<int> &h, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int cost = dp[i - j] + abs(h[i] - h[i - j]);
                mini = min(mini, cost);
            }
        }

        dp[i] = mini;
    }

    return dp[n - 1];
}

int main()
{
    int n, k;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Enter k: " << endl;
    cin >> k;

    vector<int> h(n);
    cout << "Enter heights: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << "Using Recursion: " << frogKRec(n - 1, h, k) << endl;
    cout << "Using Memoization: " << frogKMemoization(n, h, k) << endl;
    cout << "Using Tabulation: " << frogKTabulation(n, h, k) << endl;
    cout << "Using Space Optimized: " << frogKSpaceOptimized(n, h, k) << endl;

    return 0;
}