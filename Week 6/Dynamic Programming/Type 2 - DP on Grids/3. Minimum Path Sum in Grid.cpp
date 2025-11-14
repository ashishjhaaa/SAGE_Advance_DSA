/******************************************************
Problem Statement: Minimum Path Sum in a Grid

You are given an m x n grid filled with non-negative integers.
A path starts at (0,0) and ends at (m-1,n-1).
You can only move:
→ Right
→ Down

Return the minimum cost path sum.

Test Case 1:
Input:
m = 3, n = 3
grid =
1 3 1
1 5 1
4 2 1


Test Case 2:
Input:
m = 2, n = 3
grid =
5 1 3
2 1 4

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
From (i, j), two choices:
→ Move down  (i+1, j)
→ Move right (i, j+1)

Cost = grid[i][j] + min(costDown, costRight)

Base:
→ If out of bounds: return large number
→ If at destination: return grid[i][j]
----------------------------------------------------*/
int recHelper(int i, int j, vector<vector<int>> &grid, int m, int n)
{
    if (i >= m || j >= n)
    {
        return 1e9;
    }

    if (i == m - 1 && j == n - 1)
    {
        return grid[i][j];
    }

    int down = recHelper(i + 1, j, grid, m, n);
    int right = recHelper(i, j + 1, grid, m, n);

    return grid[i][j] + min(down, right);
}

int minPathRecursion(int m, int n, vector<vector<int>> &grid)
{
    return recHelper(0, 0, grid, m, n);
}

/*----------------------------------------------------
2. Memoization (Top-Down)
------------------------------------------------------
Overlapping Subproblems:
Same (i, j) is visited by different recursive branches.

dp[i][j] = minimum cost from (i,j) to (m-1,n-1)
----------------------------------------------------*/
int memoHelper(int i, int j, vector<vector<int>> &grid,
               int m, int n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 1e9;
    }

    if (i == m - 1 && j == n - 1)
    {
        return grid[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = memoHelper(i + 1, j, grid, m, n, dp);
    int right = memoHelper(i, j + 1, grid, m, n, dp);

    return dp[i][j] = grid[i][j] + min(down, right);
}

int minPathMemoization(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoHelper(0, 0, grid, m, n, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up DP)
------------------------------------------------------
dp[i][j] = min cost to reach (i, j)

Transition:
dp[i][j] = grid[i][j] + min(
    dp[i-1][j],
    dp[i][j-1]
)

dp[0][0] = grid[0][0]
----------------------------------------------------*/
int minPathTabulation(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            int up = (i > 0 ? dp[i - 1][j] : 1e9);
            int left = (j > 0 ? dp[i][j - 1] : 1e9);

            dp[i][j] = grid[i][j] + min(up, left);
        }
    }

    return dp[m - 1][n - 1];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
Use 1-D DP:
curr[j] = grid[i][j] + min(prev[j], curr[j-1])
----------------------------------------------------*/
int minPathSpaceOptimized(int m, int n, vector<vector<int>> &grid)
{
    vector<int> prev(n, 1e9), curr(n, 1e9);

    prev[0] = grid[0][0];

    for (int i = 0; i < m; i++)
    {
        curr[0] = grid[i][0] + (i == 0 ? 0 : prev[0]);

        for (int j = 1; j < n; j++)
        {
            curr[j] = grid[i][j] + min(prev[j], curr[j - 1]);
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
    cout << "Enter grid values: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "Using Recursion: " << minPathRecursion(m, n, grid) << endl;
    cout << "Using Memoization: " << minPathMemoization(m, n, grid) << endl;
    cout << "Using Tabulation: " << minPathTabulation(m, n, grid) << endl;
    cout << "Using Space Optimized: " << minPathSpaceOptimized(m, n, grid) << endl;

    return 0;
}