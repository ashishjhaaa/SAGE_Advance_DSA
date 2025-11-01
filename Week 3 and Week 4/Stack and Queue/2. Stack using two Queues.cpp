#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2; // two queues

public:
    // push operation (costly)
    void push(int val)
    {
        // step 1: push new element in q2
        q2.push(val);

        // step 2: move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // step 3: swap q1 and q2
        swap(q1, q2);
    }

    // remove top element
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        q1.pop();
    }

    // return top element
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q1.front();
    }

    // check if empty
    bool isEmpty()
    {
        return q1.empty();
    }

    // display stack elements
    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        queue<int> temp = q1; // copy for display
        cout << "Stack elements: ";
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // 30 20 10
    s.pop();
    cout << "Top element: " << s.top() << endl;
    return 0;
}