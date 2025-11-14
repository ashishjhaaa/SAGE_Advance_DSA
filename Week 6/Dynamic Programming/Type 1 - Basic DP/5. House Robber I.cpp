/******************************************************
Problem Statement: House Robber I

You are given an array where each element represents
the money present in a house. Adjacent houses cannot
be robbed on the same night.

Return the maximum money that can be robbed.

Test Case 1:
Input:
n = 4
arr = [2, 7, 9, 3]


Test Case 2:
Input:
n = 5
arr = [1, 2, 3, 1, 5]

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
1. Recursive Approach
------------------------------------------------------
At index i:
Two choices:
→ Pick the current house:
     arr[i] + solve(i-2)
→ Skip the current house:
     solve(i-1)

Return max of the two choices.
----------------------------------------------------*/

int robRec(int idx, vector<int> &arr)
{
    if (idx == 0)
    {
        return arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }

    int pick = arr[idx] + robRec(idx - 2, arr);
    int skip = robRec(idx - 1, arr);

    return max(pick, skip);
}

/*----------------------------------------------------
2. Memoization (Top-Down)
------------------------------------------------------
Overlapping Subproblems:
rob(5) uses rob(3) and rob(4)
rob(4) uses rob(3) and rob(2)
→ rob(3) and rob(2) reused multiple times.

Store results in dp[].
----------------------------------------------------*/

int robMemoHelper(int idx, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
    {
        return arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int pick = arr[idx] + robMemoHelper(idx - 2, arr, dp);
    int skip = robMemoHelper(idx - 1, arr, dp);

    return dp[idx] = max(pick, skip);
}

int robMemoization(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return robMemoHelper(n - 1, arr, dp);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up)
------------------------------------------------------
dp[0] = arr[0]
dp[i] = max(
    arr[i] + dp[i-2],
    dp[i-1]
)
----------------------------------------------------*/

int robTabulation(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        int pick = arr[i] + dp[i - 2];
        int skip = dp[i - 1];
        dp[i] = max(pick, skip);
    }

    return dp[n - 1];
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
We only need:
prev2 → dp[i-2]
prev1 → dp[i-1]

curr = max(arr[i] + prev2, prev1)
----------------------------------------------------*/

int robSpaceOptimized(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }

    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        int curr = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Using Recursion: " << robRec(n - 1, arr) << endl;
    cout << "Using Memoization: " << robMemoization(n, arr) << endl;
    cout << "Using Tabulation: " << robTabulation(n, arr) << endl;
    cout << "Using Space Optimized: " << robSpaceOptimized(n, arr) << endl;

    return 0;
}