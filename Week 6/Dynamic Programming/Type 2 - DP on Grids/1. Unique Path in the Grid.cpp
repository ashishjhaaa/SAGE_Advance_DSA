/******************************************************
Problem Statement: Unique Paths in a Grid

A robot is located at the top-left corner of an m x n grid.
The robot can only move:
→ Right
→ Down

Return the total number of unique paths to reach
the bottom-right corner.

Test Case 1:
Input:
m = 3, n = 3

Test Case 2:
Input:
m = 2, n = 3

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
At each cell (i, j) we have two choices:
→ Move down  (i+1, j)
→ Move right (i, j+1)

Total paths = paths from down + paths from right

Base Cases:
→ If we reach (m-1, n-1): return 1
→ If out of bounds: return 0
----------------------------------------------------*/
int recHelper(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }

    int down = recHelper(i + 1, j, m, n);
    int right = recHelper(i, j + 1, m, n);

    return down + right;
}

int uniquePathsRecursion(int m, int n)
{
    return recHelper(0, 0, m, n);
}

/*----------------------------------------------------
2. Memoization (Top-Down DP)
------------------------------------------------------
Overlapping Subproblems:
rec(i, j) is called many times from different paths.

Store dp[i][j] → number of paths from (i, j) to end.
----------------------------------------------------*/
int memoHelper(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = memoHelper(i + 1, j, m, n, dp);
    int right = memoHelper(i, j + 1, m, n, dp);

    return dp[i][j] = down + right;
}

int uniquePathsMemoization(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoHelper(0, 0, m, n, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
dp[i][j] = total paths to reach (i, j)

Transitions:
dp[i][j] = dp[i-1][j] + dp[i][j-1]

Base:
dp[0][0] = 1
----------------------------------------------------*/
int uniquePathsTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            int up = 0, left = 0;

            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
We only need previous row and current row.

curr[j] = prev[j] + curr[j-1]
----------------------------------------------------*/
int uniquePathsSpaceOptimized(int m, int n)
{
    vector<int> prev(n, 0), curr(n, 0);
    prev[0] = 1;

    for (int i = 0; i < m; i++)
    {
        curr[0] = 1;

        for (int j = 1; j < n; j++)
        {
            curr[j] = prev[j] + curr[j - 1];
        }

        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    int m, n;

    cout << "Enter m: " << endl;
    cin >> m;

    cout << "Enter n: " << endl;
    cin >> n;

    cout << "Using Recursion: " << uniquePathsRecursion(m, n) << endl;
    cout << "Using Memoization: " << uniquePathsMemoization(m, n) << endl;
    cout << "Using Tabulation: " << uniquePathsTabulation(m, n) << endl;
    cout << "Using Space Optimized: " << uniquePathsSpaceOptimized(m, n) << endl;

    return 0;
}