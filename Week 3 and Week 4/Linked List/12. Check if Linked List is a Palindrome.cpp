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

    // Reverse linked list helper
    Node *reverseList(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev; // new head of reversed list
    }

    // Check if linked list is palindrome
    bool isPalindrome()
    {
        if (!head || !head->next)
        {
            return true; // single node or empty list
        }
        // Step 1: Find middle (slow will point to mid)
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node *secondHalfStart = reverseList(slow->next);

        // Step 3: Compare both halves
        Node *firstHalf = head;
        Node *secondHalf = secondHalfStart;
        bool palindrome = true;

        while (secondHalf)
        {
            if (firstHalf->data != secondHalf->data)
            {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Restore the list (this is optional for safety)
        slow->next = reverseList(secondHalfStart);

        return palindrome;
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
    SinglyLL list;
    int n, val;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list.insertAtEnd(val);
    }

    if (list.isPalindrome())
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}