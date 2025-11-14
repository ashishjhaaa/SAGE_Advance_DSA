/******************************************************
Problem Statement: Minimum Falling Path Sum

You are given an n x n matrix.
A falling path starts at any cell in the first row and moves:
→ Down        (i+1, j)
→ Down-left   (i+1, j-1)
→ Down-right  (i+1, j+1)

Return the minimum falling path sum from top to bottom.

Test Case 1:
Input:
n = 3
matrix =
2 1 3
6 5 4
7 8 9


Test Case 2:
Input:
n = 3
matrix =
10 2 3
1  5 1
4  2 1


******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
From (i, j), choices:
→ Go down        (i+1, j)
→ Go down-left   (i+1, j-1)
→ Go down-right  (i+1, j+1)

Base:
→ If j is out of bounds: return large number
→ If i == n-1: return matrix[i][j]
----------------------------------------------------*/
int recHelper(int i, int j, vector<vector<int>> &mat, int n)
{
    if (j < 0 || j >= n)
    {
        return 1e9;
    }

    if (i == n - 1)
    {
        return mat[i][j];
    }

    int down = recHelper(i + 1, j, mat, n);
    int left = recHelper(i + 1, j - 1, mat, n);
    int right = recHelper(i + 1, j + 1, mat, n);

    return mat[i][j] + min(down, min(left, right));
}

int minFallingPathRecursion(int n, vector<vector<int>> &mat)
{
    int mini = INT_MAX;

    for (int j = 0; j < n; j++)
    {
        mini = min(mini, recHelper(0, j, mat, n));
    }

    return mini;
}

/*----------------------------------------------------
2. Memoization (Top-Down DP)
------------------------------------------------------
Overlapping Subproblems:
(i, j) is used by multiple upper states.

Use dp[i][j] to store result.
----------------------------------------------------*/
int memoHelper(int i, int j, vector<vector<int>> &mat,
               int n, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
    {
        return 1e9;
    }

    if (i == n - 1)
    {
        return mat[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = memoHelper(i + 1, j, mat, n, dp);
    int left = memoHelper(i + 1, j - 1, mat, n, dp);
    int right = memoHelper(i + 1, j + 1, mat, n, dp);

    return dp[i][j] = mat[i][j] + min(down, min(left, right));
}

int minFallingPathMemoization(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int mini = INT_MAX;

    for (int j = 0; j < n; j++)
    {
        mini = min(mini, memoHelper(0, j, mat, n, dp));
    }

    return mini;
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
dp[i][j] = min falling path sum reaching (i, j)

Transition:
dp[i][j] = mat[i][j] + min(
    dp[i-1][j],
    dp[i-1][j-1],
    dp[i-1][j+1]
)
----------------------------------------------------*/
int minFallingPathTabulation(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp = mat;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int down = dp[i + 1][j];
            int left = (j > 0 ? dp[i + 1][j - 1] : 1e9);
            int right = (j + 1 < n ? dp[i + 1][j + 1] : 1e9);

            dp[i][j] = mat[i][j] + min(down, min(left, right));
        }
    }

    int mini = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        mini = min(mini, dp[0][j]);
    }

    return mini;
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
Use 1-D arrays:
prev[j] = row below
curr[j] = current row computation

curr[j] = mat[i][j] + min(prev[j], prev[j-1], prev[j+1])
----------------------------------------------------*/
int minFallingPathSpaceOptimized(int n, vector<vector<int>> &mat)
{
    vector<int> prev(mat[n - 1].begin(), mat[n - 1].end());
    vector<int> curr(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int down = prev[j];
            int left = (j > 0 ? prev[j - 1] : 1e9);
            int right = (j + 1 < n ? prev[j + 1] : 1e9);

            curr[j] = mat[i][j] + min(down, min(left, right));
        }

        prev = curr;
    }

    int mini = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        mini = min(mini, prev[j]);
    }

    return mini;
}

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter matrix values:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Using Recursion: " << minFallingPathRecursion(n, mat) << endl;
    cout << "Using Memoization: " << minFallingPathMemoization(n, mat) << endl;
    cout << "Using Tabulation: " << minFallingPathTabulation(n, mat) << endl;
    cout << "Using Space Optimized: " << minFallingPathSpaceOptimized(n, mat) << endl;

    return 0;
}