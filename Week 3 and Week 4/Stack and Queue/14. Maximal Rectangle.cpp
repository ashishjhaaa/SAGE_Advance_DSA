#include <bits/stdc++.h>
using namespace std;

// helper: largest rectangle in histogram
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size(), maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int curr = (i == n) ? 0 : heights[i];

        while (!st.empty() && curr < heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

// function to find maximal rectangle in binary matrix
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }
    int n = matrix[0].size(), maxRect = 0;
    vector<int> height(n, 0);

    for (auto &row : matrix)
    {
        // update heights for histogram
        for (int j = 0; j < n; j++)
            height[j] = (row[j] == '1') ? height[j] + 1 : 0;

        // compute area for this row
        maxRect = max(maxRect, largestRectangleArea(height));
    }
    return maxRect;
}

int main()
{
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    vector<vector<char>> matrix(r, vector<char>(c));
    cout << "Enter binary matrix (0/1):\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;
    return 0;
}