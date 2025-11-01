#include <bits/stdc++.h>
using namespace std;

// function to simulate asteroid collision
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;

    for (int a : asteroids)
    {
        bool destroyed = false;

        // check collision only if stack top is positive and current is negative
        while (!st.empty() && st.top() > 0 && a < 0)
        {
            if (abs(st.top()) < abs(a))
            {
                st.pop(); // smaller one destroyed
                continue;
            }
            else if (abs(st.top()) == abs(a))
            {
                st.pop(); // both destroyed
            }
            destroyed = true; // current destroyed
            break;
        }

        if (!destroyed)
            st.push(a);
    }

    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);
    cout << "Enter asteroid values (positive = right, negative = left): ";
    for (int i = 0; i < n; i++)
    {
        cin >> asteroids[i];
    }

    vector<int> result = asteroidCollision(asteroids);

    cout << "Asteroids after collision: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
