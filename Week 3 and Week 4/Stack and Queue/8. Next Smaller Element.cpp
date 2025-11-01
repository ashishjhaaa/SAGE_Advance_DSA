#include <bits/stdc++.h>
using namespace std;

// function to find next smaller element for each element
vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, -1); // default -1 if no smaller element
    stack<int> st;          // stores indices

    for (int i = n - 1; i >= 0; i--)
    {
        // pop greater or equal elements
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        // if stack not empty, top is next smaller
        if (!st.empty())
            nse[i] = arr[st.top()];

        st.push(i);
    }
    return nse;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> res = nextSmallerElement(arr);

    cout << "Next Smaller Elements: ";
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
