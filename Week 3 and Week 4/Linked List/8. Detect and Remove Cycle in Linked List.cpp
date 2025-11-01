#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(NULL) {}

    // Insert node at end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Detect cycle using Floyd's algorithm
    bool detectCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // Remove cycle if present
    void removeCycle()
    {
        Node *slow = head;
        Node *fast = head;
        bool hasCycle = false;

        // detect meeting point
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle)
            return;

        // find start of loop
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL; // break loop
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedList list;
    int n, val;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list.insertAtEnd(val);
    }

    // Create cycle for testing (optional)
    // list.head->next->next->next = list.head;

    if (list.detectCycle())
    {
        cout << "Cycle detected\n";
        list.removeCycle();
        cout << "Cycle removed\n";
    }
    else
    {
        cout << "No cycle detected\n";
    }

    list.display();
    return 0;
}
