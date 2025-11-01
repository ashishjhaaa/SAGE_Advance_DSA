#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList
{
public:
    Node *head;
    LinkedList() { head = NULL; }

    // insert node at end
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

    // find middle node using slow-fast pointer method
    int findMiddle()
    {
        if (!head)
            return -1; // if list empty

        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;       // move one step
            fast = fast->next->next; // move two steps
        }
        return slow->data;
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
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Linked List: ";
    list.display();

    int mid = list.findMiddle();
    cout << "Middle node value: " << mid << endl;

    return 0;
}
