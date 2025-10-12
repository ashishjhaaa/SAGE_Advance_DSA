/*
    Problem : Subset Sum Equal to Target

    Statement :
    Given an array of integers and a target value, print all unique subsets
    whose sum is equal to the target. Each element can be used at most once.

    Example :
    Input  :
             n = 4
             v = [2, 3, 5, 6]
             target = 8
    Output :
             2 6
             3 5
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int target, int i, vector<int> &v, vector<int> &temp)
{
    // Base case: if target sum is achieved
    if (target == 0)
    {
        for (int j = 0; j < temp.size(); j++)
        {
            cout << temp[j] << " ";
        }
        cout << endl;
        return;
    }

    // Base case: if sum exceeds target or index crosses limit
    if (target < 0 || i == v.size())
    {
        return;
    }

    // Recursive case:
    // 1. Pick the current element
    temp.push_back(v[i]);
    solve(target - v[i], i + 1, v, temp);

    // 2. Backtrack (remove the picked element)
    temp.pop_back();

    // 3. Not pick the current element
    solve(target, i + 1, v, temp);
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

    sort(v.begin(), v.end());

    int target;
    cin >> target;

    vector<int> temp;
    solve(target, 0, v, temp);

    return 0;
}

// TC: O(2^n)
// SC: O(n)
