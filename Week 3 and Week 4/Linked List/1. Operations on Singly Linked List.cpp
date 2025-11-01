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

// Singly Linked List class
class SinglyLL
{
public:
    Node *head;

    SinglyLL()
    {
        head = NULL;
    }

    // Insert at the beginning
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    // Insert at a specific position (1-based index)
    void insertAtPosition(int pos, int val)
    {
        // Invalid position
        if (pos <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        // Insert at beginning
        if (pos == 1)
        {
            insertAtStart(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *tail = head;

        // Traverse to (pos-1)th node
        for (int i = 1; tail != NULL && i < pos - 1; i++)
        {
            tail = tail->next;
        }

        // If position exceeds length
        if (tail == NULL)
        {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    // Delete from the beginning
    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // If there is only one node
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *tail = head;
        while (tail->next->next != NULL)
        {
            tail = tail->next;
        }

        delete tail->next;
        tail->next = NULL;
    }

    // Delete at a given position (1-based)
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        // Delete first node
        if (pos == 1)
        {
            deleteFromStart();
            return;
        }

        Node *tail = head;
        // Move to (pos-1)th node
        for (int i = 1; tail != NULL && i < pos - 1; i++)
        {
            tail = tail->next;
        }

        // If position invalid or out of range
        if (tail == NULL || tail->next == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        Node *temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }

    // Display linked list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLL list;

    // Insert operations
    list.insertAtStart(10);
    list.display(); // 10

    list.insertAtEnd(30);
    list.display(); // 10 -> 30

    list.insertAtPosition(2, 20);
    list.display(); // 10 -> 20 -> 30

    list.insertAtEnd(40);
    list.display(); // 10 -> 20 -> 30 -> 40

    // Delete operations
    list.deleteFromStart();
    list.display(); // 20 -> 30 -> 40

    list.deleteFromEnd();
    list.display(); // 20 -> 30

    list.deleteAtPosition(2);
    list.display(); // 20

    // Edge cases
    list.deleteAtPosition(5); // out of range
    list.deleteFromEnd();     // delete last node
    list.display();           // empty list
    list.deleteFromStart();   // list empty already

    return 0;
}