/******************************************************
Problem Statement: Unique Paths II (Grid With Obstacles)

A robot is at the top-left corner of an m x n grid.
Some cells contain obstacles marked as 1.

Robot can move:
→ Right
→ Down

Return the total number of unique paths to reach the
bottom-right cell, avoiding obstacles.

If the start or end cell has an obstacle, return 0.

Test Case 1:
Input:
m = 3, n = 3
grid =
0 0 0
0 1 0
0 0 0


Test Case 2:
Input:
m = 2, n = 3
grid =
0 1 0
0 0 0

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
Choices from cell (i, j):
→ Move down  (i+1, j)
→ Move right (i, j+1)

Stop if:
→ cell is out of bounds
→ cell has obstacle (value = 1)
→ reached destination
----------------------------------------------------*/
int recHelper(int i, int j, vector<vector<int>> &grid, int m, int n)
{
    if (i >= m || j >= n)
    {
        return 0;
    }

    if (grid[i][j] == 1)
    {
        return 0;
    }

    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    int down = recHelper(i + 1, j, grid, m, n);
    int right = recHelper(i, j + 1, grid, m, n);

    return down + right;
}

int uniquePathsRecursion(int m, int n, vector<vector<int>> &grid)
{
    return recHelper(0, 0, grid, m, n);
}

/*----------------------------------------------------
2. Memoization (Top-Down)
------------------------------------------------------
Overlapping Subproblems:
(1,1) is called by both (0,1) and (1,0)
→ Use dp[i][j] to store number of paths from (i,j)
----------------------------------------------------*/
int memoHelper(int i, int j, vector<vector<int>> &grid,
               int m, int n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 0;
    }

    if (grid[i][j] == 1)
    {
        return 0;
    }

    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = memoHelper(i + 1, j, grid, m, n, dp);
    int right = memoHelper(i, j + 1, grid, m, n, dp);

    return dp[i][j] = down + right;
}

int uniquePathsMemoization(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoHelper(0, 0, grid, m, n, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up)
------------------------------------------------------
dp[i][j] = total ways to reach (i, j)

Rules:
→ If obstacle: dp[i][j] = 0
→ Else: dp[i][j] = dp[i-1][j] + dp[i][j-1]
----------------------------------------------------*/
int uniquePathsTabulation(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (grid[0][0] == 1)
    {
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }

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
Use only 1-D DP array:
curr[j] = (obstacle? 0 : curr[j-1] + prev[j])
----------------------------------------------------*/
int uniquePathsSpaceOptimized(int m, int n, vector<vector<int>> &grid)
{
    vector<int> prev(n, 0), curr(n, 0);

    if (grid[0][0] == 1)
    {
        return 0;
    }

    prev[0] = 1;

    for (int i = 0; i < m; i++)
    {
        curr[0] = (grid[i][0] == 1 ? 0 : prev[0]);

        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                curr[j] = 0;
            }
            else
            {
                curr[j] = prev[j] + curr[j - 1];
            }
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

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid values (0 for empty, 1 for obstacle): " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "Using Recursion: " << uniquePathsRecursion(m, n, grid) << endl;
    cout << "Using Memoization: " << uniquePathsMemoization(m, n, grid) << endl;
    cout << "Using Tabulation: " << uniquePathsTabulation(m, n, grid) << endl;
    cout << "Using Space Optimized: " << uniquePathsSpaceOptimized(m, n, grid) << endl;

    return 0;
}