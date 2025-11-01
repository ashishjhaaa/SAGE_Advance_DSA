#include <bits/stdc++.h>
using namespace std;

/// Doubly linked list structure
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

/// All methods performed on DoublyLL
class DoublyLL
{
public:
    Node *head;

    DoublyLL() { head = NULL; }

    // Insert at beginning
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        tail->next = newNode;
        newNode->prev = tail;
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

        // Move to node just before desired position
        for (int i = 1; tail != NULL && i < pos - 1; i++)
            tail = tail->next;

        // If position is beyond length, insert at end
        if (tail == NULL)
        {
            cout << "Position out of range. Inserting at end." << endl;
            insertAtEnd(val);
            return;
        }

        Node *temp = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = temp;
        if (temp != NULL)
            temp->prev = newNode;
    }

    // Delete from beginning
    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
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

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        tail->prev->next = NULL;
        delete tail;
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
        for (int i = 1; tail != NULL && i < pos; i++)
            tail = tail->next;

        if (tail == NULL)
        {
            cout << "Position out of range" << endl;
            return;
        }

        // Adjust pointers
        if (tail->prev != NULL)
            tail->prev->next = tail->next;
        if (tail->next != NULL)
            tail->next->prev = tail->prev;

        delete tail;
    }

    // Display list forward
    void displayForward()
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }

        Node *tail = head;
        while (tail != NULL)
        {
            cout << tail->data << " <-> ";
            tail = tail->next;
        }
        cout << "NULL" << endl;
    }

    // Display list backward
    void displayBackward()
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }

        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        while (tail != NULL)
        {
            cout << tail->data << " <-> ";
            tail = tail->prev;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLL list;
    list.insertAtStart(10);
    list.displayForward();

    list.insertAtEnd(30);
    list.displayForward();

    list.insertAtPosition(2, 20);
    list.displayForward();

    list.insertAtPosition(10, 50); // test out-of-range case
    list.displayForward();

    list.deleteAtPosition(1);
    list.displayForward();

    list.deleteFromEnd();
    list.displayForward();

    list.deleteAtPosition(2);
    list.displayForward();

    return 0;
}
