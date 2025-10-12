/*
    Problem : Count Paths in a Grid with Obstacles

    Statement :
    Given an n x m grid, some cells may have obstacles represented by -1.
    A person starts at the top-left cell (0,0) and can move only right or down.
    Find the total number of unique paths to reach the bottom-right cell
    while avoiding obstacles.

    Example :
    Input  :
             n = 3, m = 3
             grid = [[0,0,0],
                     [0,-1,0],
                     [0,0,0]]
    Output :
             2

    Explanation :
    There are two paths from (0,0) to (2,2) avoiding obstacles.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> grid)
{
    // Base case: out of bounds
    if (i >= grid.size() || j >= grid[0].size())
    {
        return 0;
    }

    // Base case: cell is an obstacle
    if (grid[i][j] == -1)
    {
        return 0;
    }

    // Base case: reached destination
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
    {
        return 1;
    }

    // Recursive case:
    int right = solve(i, j + 1, grid); // Move right
    int down = solve(i + 1, j, grid);  // Move down

    return right + down;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << solve(0, 0, v) << endl;

    return 0;
}

// TC: O(2^(n*m))
// SC: O(n + m)