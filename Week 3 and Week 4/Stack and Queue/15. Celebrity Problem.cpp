#include <bits/stdc++.h>
using namespace std;

// function to find celebrity in a party
int findCelebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    // push all people into stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // find potential celebrity
    while (st.size() > 1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();

        // if A knows B -> A not celebrity
        if (M[A][B] == 1)
        {
            st.push(B);
        }
        else
        {
            st.push(A);
        }
    }

    int cand = st.top(); // potential celebrity

    // verify candidate
    for (int i = 0; i < n; i++)
    {
        if (i == cand)
        {
            continue;
        }

        // celebrity doesn't know anyone, everyone knows celebrity
        if (M[cand][i] == 1 || M[i][cand] == 0)
        {
            return -1;
        }
    }
    return cand;
}

int main()
{
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter matrix (" << n << "x" << n << ") where M[i][j]=1 means i knows j:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }

    int celeb = findCelebrity(M, n);

    if (celeb == -1)
    {
        cout << "No celebrity found.\n";
    }
    else
    {
        cout << "Celebrity is person index: " << celeb << endl;
    }

    return 0;
}