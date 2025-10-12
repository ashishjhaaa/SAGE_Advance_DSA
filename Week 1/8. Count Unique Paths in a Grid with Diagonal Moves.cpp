/*
    Problem : Count Unique Paths in a Grid with Diagonal Moves

    Statement :
    Given an n x m grid, a person starts at cell (1,1) and can move
    either right, down, or diagonally (down-right) at each step.
    The task is to find the total number of unique paths to reach
    cell (n,m).

    Example :
    Input  :
             n = 2, m = 2
    Output :
             3

    Explanation :
    Possible paths:
    1 → Right → Down
    1 → Down → Right
    1 → Diagonal → Destination
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m)
{
    // Base case: reached destination
    if (i == n && j == m)
    {
        return 1;
    }

    // Out of bounds
    if (i == n + 1 || j == m + 1)
    {
        return 0;
    }

    // Recursive case:
    int right = solve(i, j + 1, n, m);        // Move right
    int down = solve(i + 1, j, n, m);         // Move down
    int diagonal = solve(i + 1, j + 1, n, m); // Move diagonally

    return right + down + diagonal;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << solve(1, 1, n, m) << endl;

    return 0;
}

// TC: O(3^(n+m))
// SC: O(n + m)
