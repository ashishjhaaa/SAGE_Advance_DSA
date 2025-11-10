#include <bits/stdc++.h>
using namespace std;

/// singly linked list structure
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

    // Insert node at the end
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

    // Merge two sorted linked lists (static method)
    static Node *mergeTwoLists(Node *l1, Node *l2)
    {
        // Dummy node for ease of handling the head
        Node dummy(0);
        Node *tail = &dummy;

        // Merge both lists while both have nodes
        while (l1 && l2)
        {
            if (l1->data < l2->data)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach if there is any remaining nodes
        if (l1)
        {
            tail->next = l1;
        }
        else
        {
            tail->next = l2;
        }

        // Return merged list head node
        return dummy.next;
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
    SinglyLL list1, list2, merged;
    int n1, n2, val;

    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        list1.insertAtEnd(val);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        list2.insertAtEnd(val);
    }

    // this is the way to do - static call using the class name
    merged.head = SinglyLL::mergeTwoLists(list1.head, list2.head);
    merged.display();

    return 0;
}