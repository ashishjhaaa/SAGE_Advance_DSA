#include <bits/stdc++.h>
using namespace std;

// function to find next greater element for each element in array
vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, -1); // default -1 if no greater element
    stack<int> st;          // stores indices

    for (int i = n - 1; i >= 0; i--)
    {
        // pop smaller elements
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        // if stack not empty, top is next greater
        if (!st.empty())
            nge[i] = arr[st.top()];

        st.push(i);
    }
    return nge;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
