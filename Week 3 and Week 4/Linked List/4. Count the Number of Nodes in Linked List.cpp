#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
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

    // insert at end
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

    // count total nodes
    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // display list
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

    cout << "Total number of nodes: " << list.countNodes() << endl;

    return 0;
}
