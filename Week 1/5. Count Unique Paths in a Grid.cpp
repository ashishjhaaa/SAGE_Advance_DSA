/*
    Problem : Count Unique Paths in a Grid (Dynamic Programming)

    Statement :
    Given a grid of size n x m, a person can move only to the right or down
    from any cell. The task is to find the number of unique paths from the
    top-left corner (0,0) to the bottom-right corner (n-1,m-1).

    Example :
    Input  :
             n = 3, m = 3
    Output :
             6

    Explanation :
    There are 6 unique paths from (0,0) to (2,2) if movements are allowed only
    rightward and downward.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));

    int i, j;
    cin >> i >> j; // (not used further in logic)

    // Fill the grid in bottom-up manner
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                v[n - 1][m - 1] = 1;
                continue;
            }

            // Sum of paths from the cell below and right
            v[i][j] = v[i + 1][j] + v[i][j + 1];
        }
    }

    // Print the DP matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(n * m)
// SC: O(n * m)
