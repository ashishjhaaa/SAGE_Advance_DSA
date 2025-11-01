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

    void reverseList()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev; // reverse link
            prev = curr;
            curr = next;
        }
        head = prev;
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
    list.reverseList();
    list.display();
}
