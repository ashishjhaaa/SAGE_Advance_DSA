#include <bits/stdc++.h>
using namespace std;

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

class SinglyLL
{
public:
    Node *head;

    SinglyLL()
    {
        head = NULL;
    }

    // Insert node at end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Remove duplicates from sorted linked list
    void removeDuplicates()
    {
        Node *temp = head;

        // Traverse and skip duplicate nodes
        while (temp && temp->next)
        {
            if (temp->data == temp->next->data)
            {
                temp->next = temp->next->next; // skip duplicate
            }
            else
            {
                temp = temp->next; // move ahead
            }
        }
    }

    // Display linked list
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
    SinglyLL list;
    int n, val;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list.insertAtEnd(val);
    }

    list.removeDuplicates();
    list.display();

    return 0;
}