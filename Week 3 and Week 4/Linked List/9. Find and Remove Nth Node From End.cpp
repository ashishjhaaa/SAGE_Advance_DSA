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

    void removeNthFromEnd(int n)
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *fast = dummy;
        Node *slow = dummy;

        // move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++)
        {
            if (!fast)
                return;
            fast = fast->next;
        }

        // move both till fast reaches end
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // delete target node
        Node *del = slow->next;
        if (del)
            slow->next = del->next;

        head = dummy->next;
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

    int k;
    cin >> k;

    list.removeNthFromEnd(k);
    list.display();

    return 0;
}
