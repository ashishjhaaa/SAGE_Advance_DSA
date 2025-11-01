#include <bits/stdc++.h>
using namespace std;

// function to find previous greater element for each element
vector<int> previousGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pge(n, -1); // default -1 if no greater element before
    stack<int> st;          // stores elements (not indices)

    for (int i = 0; i < n; i++)
    {
        // pop smaller or equal elements
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        // if stack not empty, top is previous greater
        if (!st.empty())
            pge[i] = st.top();

        st.push(arr[i]);
    }
    return pge;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = previousGreaterElement(arr);

    cout << "Previous Greater Elements: ";
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
