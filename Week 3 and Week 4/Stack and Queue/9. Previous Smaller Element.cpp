#include <bits/stdc++.h>
using namespace std;

// function to find previous smaller element for each element
vector<int> previousSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, -1); // default -1 if no smaller element before
    stack<int> st;          // stores elements (not indices)

    for (int i = 0; i < n; i++)
    {
        // pop greater or equal elements
        while (!st.empty() && st.top() >= arr[i])
            st.pop();

        // if stack not empty, top is previous smaller
        if (!st.empty())
            pse[i] = st.top();

        st.push(arr[i]);
    }
    return pse;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = previousSmallerElement(arr);

    cout << "Previous Smaller Elements: ";
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
