/******************************************************
Problem Statement: Frog Jump

A frog is at index 0 and wants to reach index n-1.
He can jump either:
→ 1 step
→ 2 steps

Energy cost for jumping from i to j:
abs(heights[i] - heights[j])

Return the minimum total energy required.

Test Case 1:
Input:
n = 4
heights = [10, 20, 30, 10]

Test Case 2:
Input:
n = 3
heights = [30, 10, 60]

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
At every index we have two choices:
→ Jump 1 step: cost = abs(h[i] - h[i-1]) + solve(i-1)
→ Jump 2 steps: cost = abs(h[i] - h[i-2]) + solve(i-2)

We pick the minimum of the two.
----------------------------------------------------*/

int frogRec(int idx, vector<int> &h)
{
    if (idx == 0)
    {
        return 0;
    }

    int one = frogRec(idx - 1, h) + abs(h[idx] - h[idx - 1]);

    int two = INT_MAX;
    if (idx > 1)
    {
        two = frogRec(idx - 2, h) + abs(h[idx] - h[idx - 2]);
    }

    return min(one, two);
}

/*----------------------------------------------------
2. Memoization (Top-Down DP)
------------------------------------------------------
Overlapping Subproblems:
solve(4) depends on solve(3) and solve(2)
solve(3) depends on solve(2) and solve(1)
solve(2) depends on solve(1) and solve(0)

→ solve(2), solve(1) repeatedly computed.
----------------------------------------------------*/

int frogMemoHelper(int idx, vector<int> &h, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int one = frogMemoHelper(idx - 1, h, dp) + abs(h[idx] - h[idx - 1]);

    int two = INT_MAX;
    if (idx > 1)
    {
        two = frogMemoHelper(idx - 2, h, dp) + abs(h[idx] - h[idx - 2]);
    }

    return dp[idx] = min(one, two);
}

int frogMemoization(int n, vector<int> &h)
{
    vector<int> dp(n, -1);
    return frogMemoHelper(n - 1, h, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
dp[i] = minimum cost to reach index i
dp[0] = 0
dp[1] = abs(h[1] - h[0])
dp[i] = min(
    dp[i-1] + abs(h[i] - h[i-1]),
    dp[i-2] + abs(h[i] - h[i-2])
)
----------------------------------------------------*/

int frogTabulation(int n, vector<int> &h)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int one = dp[i - 1] + abs(h[i] - h[i - 1]);

        int two = INT_MAX;
        if (i > 1)
        {
            two = dp[i - 2] + abs(h[i] - h[i - 2]);
        }

        dp[i] = min(one, two);
    }

    return dp[n - 1];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
Only dp[i-1] and dp[i-2] are needed.
We keep two variables:
prev1 → dp[i-1]
prev2 → dp[i-2]
----------------------------------------------------*/

int frogSpaceOptimized(int n, vector<int> &h)
{
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 1; i < n; i++)
    {
        int one = prev1 + abs(h[i] - h[i - 1]);

        int two = INT_MAX;
        if (i > 1)
        {
            two = prev2 + abs(h[i] - h[i - 2]);
        }

        int curr = min(one, two);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    vector<int> h(n);
    cout << "Enter heights: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << "Using Recursion: " << frogRec(n - 1, h) << endl;
    cout << "Using Memoization: " << frogMemoization(n, h) << endl;
    cout << "Using Tabulation: " << frogTabulation(n, h) << endl;
    cout << "Using Space Optimized: " << frogSpaceOptimized(n, h) << endl;

    return 0;
}