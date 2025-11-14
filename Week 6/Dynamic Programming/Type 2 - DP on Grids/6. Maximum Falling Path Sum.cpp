/******************************************************
Problem Statement: Maximum Falling Path Sum

You are given an n x n matrix.
A falling path starts at any cell in the first row and moves:
→ Down        (i+1, j)
→ Down-left   (i+1, j-1)
→ Down-right  (i+1, j+1)

Return the maximum falling path sum from top to bottom.

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
At (i, j), 3 possible moves:
→ Down        (i+1, j)
→ Down-left   (i+1, j-1)
→ Down-right  (i+1, j+1)

Base:
→ If j out of bounds: return very small
→ If i == n-1: return mat[i][j]
----------------------------------------------------*/
int recHelper(int i, int j, vector<vector<int>> &mat, int n)
{
    if (j < 0 || j >= n)
    {
        return -1e9;
    }

    if (i == n - 1)
    {
        return mat[i][j];
    }

    int down = recHelper(i + 1, j, mat, n);
    int left = recHelper(i + 1, j - 1, mat, n);
    int right = recHelper(i + 1, j + 1, mat, n);

    return mat[i][j] + max(down, max(left, right));
}

int maxFallingPathRecursion(int n, vector<vector<int>> &mat)
{
    int maxi = INT_MIN;

    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, recHelper(0, j, mat, n));
    }

    return maxi;
}

/*----------------------------------------------------
2. Memoization (Top-Down)
------------------------------------------------------
Overlapping Subproblems:
(i, j) is reused from multiple paths.

dp[i][j] stores maximum sum from (i,j) to bottom.
----------------------------------------------------*/
int memoHelper(int i, int j, vector<vector<int>> &mat,
               int n, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
    {
        return -1e9;
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

    return dp[i][j] = mat[i][j] + max(down, max(left, right));
}

int maxFallingPathMemoization(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int maxi = INT_MIN;

    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, memoHelper(0, j, mat, n, dp));
    }

    return maxi;
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
Transition:
dp[i][j] = mat[i][j] + max(
    dp[i+1][j],
    dp[i+1][j-1],
    dp[i+1][j+1]
)
----------------------------------------------------*/
int maxFallingPathTabulation(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp = mat;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int down = dp[i + 1][j];
            int left = (j > 0 ? dp[i + 1][j - 1] : -1e9);
            int right = (j + 1 < n ? dp[i + 1][j + 1] : -1e9);

            dp[i][j] = mat[i][j] + max(down, max(left, right));
        }
    }

    int maxi = INT_MIN;
    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, dp[0][j]);
    }

    return maxi;
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
Use prev[] and curr[] arrays of size n.

curr[j] = mat[i][j] + max(prev[j], prev[j-1], prev[j+1])
----------------------------------------------------*/
int maxFallingPathSpaceOptimized(int n, vector<vector<int>> &mat)
{
    vector<int> prev(mat[n - 1].begin(), mat[n - 1].end());
    vector<int> curr(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int down = prev[j];
            int left = (j > 0 ? prev[j - 1] : -1e9);
            int right = (j + 1 < n ? prev[j + 1] : -1e9);

            curr[j] = mat[i][j] + max(down, max(left, right));
        }

        prev = curr;
    }

    int maxi = INT_MIN;
    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
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

    cout << "Using Recursion: " << maxFallingPathRecursion(n, mat) << endl;
    cout << "Using Memoization: " << maxFallingPathMemoization(n, mat) << endl;
    cout << "Using Tabulation: " << maxFallingPathTabulation(n, mat) << endl;
    cout << "Using Space Optimized: " << maxFallingPathSpaceOptimized(n, mat) << endl;

    return 0;
}