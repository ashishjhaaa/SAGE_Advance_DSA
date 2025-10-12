/*
    Problem : Subset Sum (All Possible Subset Sums)

    Statement :
    Given an array of integers, print the sum of all possible subsets
    that can be formed using the elements of the array.

    Example :
    Input  :
             n = 3
             v = [2, 3, 5]
    Output :
             10 5 7 2 8 3 5 0

    Explanation :
    Each value represents the sum of one subset:
    [2,3,5]=10 , [3,5]=8 , [2,5]=7 , [2,3]=5 , [5]=5 , [3]=3 , [2]=2 , []=0
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<int> v, int currSum)
{
    // Base case: when all elements are processed
    if (i == v.size())
    {
        cout << currSum << " ";
        return;
    }

    // Recursive case:
    // 1. Pick the current element
    solve(i + 1, v, currSum + v[i]);

    // 2. Not pick the current element
    solve(i + 1, v, currSum);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    solve(0, v, 0);

    return 0;
}

// TC: O(2^n)
// SC: O(n)
