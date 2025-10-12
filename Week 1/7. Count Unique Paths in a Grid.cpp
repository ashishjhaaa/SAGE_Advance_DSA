/*
    Problem : Count Unique Paths in a Grid (Recursive Approach)

    Statement :
    Given an n x m grid, a person starts at cell (1,1) and can move only
    either right or down at each step. The task is to find the total
    number of unique paths to reach cell (n,m).

    Example :
    Input  :
             n = 3, m = 3
    Output :
             6

    Explanation :
    From (1,1) → (3,3), there are 6 unique paths possible
    when moving only right or down.
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
    // Move right
    int right = solve(i, j + 1, n, m);

    // Move down
    int down = solve(i + 1, j, n, m);

    return right + down;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << solve(1, 1, n, m) << endl;

    return 0;
}

// TC: O(2^(n+m))
// SC: O(n + m)
