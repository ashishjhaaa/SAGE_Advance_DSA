#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int arr[100]; // static array
    int top;      // index of top element

public:
    Stack() { top = -1; }

    // push element in stack
    void push(int val)
    {
        if (top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    // remove element from top
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // return top element
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // check if empty
    bool isEmpty()
    {
        return top == -1;
    }

    // display elements
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
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
    cout << "Top element: " << s.peek() << endl;
    return 0;
}
