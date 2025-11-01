#include <bits/stdc++.h>
using namespace std;

/// Circular linked list structure
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

// All methods performed on CircularLL
class CircularLL
{
public:
    Node *head;

    CircularLL() { head = NULL; }

    // Insert at beginning
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *tail = head;
        while (tail->next != head)
            tail = tail->next;

        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *tail = head;
        while (tail->next != head)
            tail = tail->next;

        tail->next = newNode;
        newNode->next = head;
    }

    // Insert at given position (1-based)
    void insertAtPosition(int pos, int val)
    {
        if (pos <= 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            insertAtStart(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *tail = head;

        int count = 1;
        while (tail->next != head && count < pos - 1)
        {
            tail = tail->next;
            count++;
        }

        // If position beyond length → insert at end
        if (tail->next == head && count < pos - 1)
        {
            cout << "Position out of range. Inserting at end." << endl;
            insertAtEnd(val);
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    // Delete from beginning
    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        { // only one node
            delete head;
            head = NULL;
            return;
        }

        Node *tail = head;
        while (tail->next != head)
            tail = tail->next;

        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        { // single node
            delete head;
            head = NULL;
            return;
        }

        Node *tail = head;
        while (tail->next->next != head)
            tail = tail->next;

        Node *temp = tail->next;
        tail->next = head;
        delete temp;
    }

    // Delete at given position
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (pos <= 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            deleteFromStart();
            return;
        }

        Node *tail = head;
        int count = 1;

        while (tail->next != head && count < pos - 1)
        {
            tail = tail->next;
            count++;
        }

        // if position out of range
        if (tail->next == head)
        {
            cout << "Position out of range" << endl;
            return;
        }

        Node *temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }

    // Display circular list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *tail = head;
        cout << "List: ";
        do
        {
            cout << tail->data << " -> ";
            tail = tail->next;
        } while (tail != head);

        cout << "(head)" << endl;
    }
};

int main()
{
    CircularLL list;

    list.insertAtStart(10);
    list.display();

    list.insertAtEnd(30);
    list.display();

    list.insertAtPosition(2, 20);
    list.display();

    list.insertAtEnd(40);
    list.display();

    list.deleteFromStart();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteAtPosition(1);
    list.display();

    list.deleteAtPosition(10); // test out-of-range case
    list.display();

    return 0;
}
