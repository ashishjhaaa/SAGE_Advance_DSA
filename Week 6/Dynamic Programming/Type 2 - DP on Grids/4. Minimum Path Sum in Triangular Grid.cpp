/******************************************************
Problem Statement: Minimum Path Sum in a Triangular Grid

You are given a triangular grid of size n.
At each step, you may move:
→ Down to (i+1, j)
→ Diagonally down-right to (i+1, j+1)

Return the minimum path sum from the top to the bottom.

Test Case 1:
Input:
n = 4
triangle =
2
3 4
6 5 7
4 1 8 3


Test Case 2:
Input:
n = 3
triangle =
1
2 3
3 6 7

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
At each cell (i, j), choices:
→ Move down:        solve(i+1, j)
→ Move diagonal:    solve(i+1, j+1)

Base:
→ If i == n-1: return triangle[i][j]
----------------------------------------------------*/
int recHelper(int i, int j, vector<vector<int>> &tri, int n)
{
    if (i == n - 1)
    {
        return tri[i][j];
    }

    int down = recHelper(i + 1, j, tri, n);
    int diag = recHelper(i + 1, j + 1, tri, n);

    return tri[i][j] + min(down, diag);
}

int minTriangleRecursion(int n, vector<vector<int>> &tri)
{
    return recHelper(0, 0, tri, n);
}

/*----------------------------------------------------
2. Memoization (Top-Down)
------------------------------------------------------
Overlapping Subproblems:
(i, j) is visited from both (i-1, j) and (i-1, j-1)
Use dp[i][j] to store result.
----------------------------------------------------*/
int memoHelper(int i, int j, vector<vector<int>> &tri,
               int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return tri[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = memoHelper(i + 1, j, tri, n, dp);
    int diag = memoHelper(i + 1, j + 1, tri, n, dp);

    return dp[i][j] = tri[i][j] + min(down, diag);
}

int minTriangleMemoization(int n, vector<vector<int>> &tri)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return memoHelper(0, 0, tri, n, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up)
------------------------------------------------------
Start filling dp from the last row upward.

Transition:
dp[i][j] = tri[i][j] + min(
    dp[i+1][j],
    dp[i+1][j+1]
)
----------------------------------------------------*/
int minTriangleTabulation(int n, vector<vector<int>> &tri)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = tri[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = tri[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
Use a single 1-D array representing the row below.

curr[j] = tri[i][j] + min(prev[j], prev[j+1])
----------------------------------------------------*/
int minTriangleSpaceOptimized(int n, vector<vector<int>> &tri)
{
    vector<int> prev(tri[n - 1].begin(), tri[n - 1].end());
    vector<int> curr(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            curr[j] = tri[i][j] + min(prev[j], prev[j + 1]);
        }
        prev = curr;
    }

    return prev[0];
}

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    vector<vector<int>> tri(n);
    cout << "Enter triangle values row-wise:" << endl;

    for (int i = 0; i < n; i++)
    {
        tri[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }

    cout << "Using Recursion: " << minTriangleRecursion(n, tri) << endl;
    cout << "Using Memoization: " << minTriangleMemoization(n, tri) << endl;
    cout << "Using Tabulation: " << minTriangleTabulation(n, tri) << endl;
    cout << "Using Space Optimized: " << minTriangleSpaceOptimized(n, tri) << endl;

    return 0;
}