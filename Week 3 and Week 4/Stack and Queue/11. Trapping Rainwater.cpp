#include <bits/stdc++.h>
using namespace std;

// function to calculate trapped rainwater
int trapRainWater(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(leftMax[i], rightMax[i]) - height[i]; // trapped water at i
    }
    return water;
}

int main()
{
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter bar heights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << "Total trapped water: " << trapRainWater(height) << endl;
    return 0;
}
