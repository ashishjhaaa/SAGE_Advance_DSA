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

    // Add two numbers by linked lists
    static Node *addTwoNumbers(Node *l1, Node *l2)
    {
        Node dummy(0);  
        Node *curr = &dummy; 
        int carry = 0;   

        // Traverse both lists
        while (l1 || l2 || carry)
        {
            int sum = carry;

            if (l1)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            carry = sum / 10;                // Update carry
            curr->next = new Node(sum % 10); // Store current digit
            curr = curr->next;
        }

        return dummy.next; // Return head of new list
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
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLL list1, list2, result;
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

    // Static call using class name
    result.head = SinglyLL::addTwoNumbers(list1.head, list2.head);

    result.display();

    return 0;
}