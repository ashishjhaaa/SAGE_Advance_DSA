#include <bits/stdc++.h>
using namespace std;

// function to find largest rectangle area in histogram
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        // current height, 0 for handling remaining bars
        int curr = (i == n) ? 0 : heights[i];

        // pop until we find smaller height
        while (!st.empty() && curr < heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();

            // width = rightIndex - leftIndex - 1
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    return maxArea;
}

int main()
{
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter bar heights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
