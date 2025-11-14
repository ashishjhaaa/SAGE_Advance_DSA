/******************************************************
Problem Statement: House Robber II (Circular)

You are given an array where each element represents
the money in a house. The houses are arranged in a circle,
which means:

→ First house and last house are adjacent.
→ You cannot rob both of them together.

Return the maximum money that can be robbed.

Test Case 1:
Input:
n = 4
arr = [2, 3, 2, 3]

Test Case 2:
Input:
n = 5
arr = [1, 2, 3, 1, 5]

******************************************************/

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------
Recursive helper for linear robber
Two Choices:
→ Pick current: arr[i] + solve(i-2)
→ Skip current: solve(i-1)
----------------------------------------------------*/
int robRecLinear(int idx, vector<int> &arr)
{
    if (idx == 0)
    {
        return arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }

    int pick = arr[idx] + robRecLinear(idx - 2, arr);
    int skip = robRecLinear(idx - 1, arr);

    return max(pick, skip);
}

/*----------------------------------------------------
1. Recursive Approach for Circular
------------------------------------------------------
Since first and last house cannot be robbed together:
Case A: Rob houses from index [0 → n-2]
Case B: Rob houses from index [1 → n-1]

Answer = max(Case A, Case B)
----------------------------------------------------*/
int robRecCircular(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }

    vector<int> caseA(arr.begin(), arr.end() - 1);
    vector<int> caseB(arr.begin() + 1, arr.end());

    return max(robRecLinear(n - 2, caseA), robRecLinear(n - 2, caseB));
}

/*----------------------------------------------------
2. Memoization (Top-Down)
------------------------------------------------------
Overlapping Subproblems present in linear DP.
Same logic as House Robber I but applied twice:
→ Excluding last house
→ Excluding first house
----------------------------------------------------*/
int memoHelper(int idx, vector<int> &arr, vector<int> &dp)
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

    int pick = arr[idx] + memoHelper(idx - 2, arr, dp);
    int skip = memoHelper(idx - 1, arr, dp);

    return dp[idx] = max(pick, skip);
}

int robMemoization(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }

    vector<int> caseA(arr.begin(), arr.end() - 1);
    vector<int> caseB(arr.begin() + 1, arr.end());

    vector<int> dpA(n, -1), dpB(n, -1);

    int ansA = memoHelper(n - 2, caseA, dpA);
    int ansB = memoHelper(n - 2, caseB, dpB);

    return max(ansA, ansB);
}

/*----------------------------------------------------
3. Tabulation (Bottom-Up)
------------------------------------------------------
We convert the circular problem into two linear cases:
dp[i] = max(arr[i] + dp[i-2], dp[i-1])
----------------------------------------------------*/
int solveTab(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int robTabulation(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }

    vector<int> caseA(arr.begin(), arr.end() - 1);
    vector<int> caseB(arr.begin() + 1, arr.end());

    return max(solveTab(caseA), solveTab(caseB));
}

/*----------------------------------------------------
4. Space Optimized Approach
------------------------------------------------------
Only keep prev2 and prev1 values for the linear DP.
Do it twice for two cases.
----------------------------------------------------*/
int solveSpaceOpt(vector<int> &arr)
{
    int n = arr.size();
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

int robSpaceOptimized(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }

    vector<int> caseA(arr.begin(), arr.end() - 1);
    vector<int> caseB(arr.begin() + 1, arr.end());

    return max(solveSpaceOpt(caseA), solveSpaceOpt(caseB));
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

    cout << "Using Recursion: " << robRecCircular(n, arr) << endl;
    cout << "Using Memoization: " << robMemoization(n, arr) << endl;
    cout << "Using Tabulation: " << robTabulation(n, arr) << endl;
    cout << "Using Space Optimized: " << robSpaceOptimized(n, arr) << endl;

    return 0;
}