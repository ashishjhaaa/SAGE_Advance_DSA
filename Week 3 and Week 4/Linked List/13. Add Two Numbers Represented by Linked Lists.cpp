#include <bits/stdc++.h>
using namespace std;

/// singly linked list node structure
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

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    // insert a node at the end
    void insertNode(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    // reverse linked list
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
        return prev;
    }

    // add two numbers normally
    Node *addNumbers(Node *l1, Node *l2)
    {
        int carry = 0;
        Node *dummy = new Node(0);
        Node *tail = dummy;

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

            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }
        return dummy->next;
    }

    // print linked list
    void printList(Node *tail)
    {
        while (tail)
        {
            cout << tail->data << " -> ";
            tail = tail->next;
        }
        cout << "NULL" << endl;
    }
};

// function to add two numbers represented by linked lists
Node *solve(Node *l1, Node *l2, SinglyLinkedList &helper)
{
    // Step 1: Reverse both lists
    l1 = helper.reverseList(l1);
    l2 = helper.reverseList(l2);

    // Step 2: Add normally
    Node *sumList = helper.addNumbers(l1, l2);

    // Step 3: Reverse the resultant list
    sumList = helper.reverseList(sumList);

    return sumList;
}

int main()
{
    SinglyLinkedList l1, l2, helper;

    // first list: 9 -> 1 -> 5
    l1.insertNode(9);
    l1.insertNode(1);
    l1.insertNode(5);

    // second list: 2 -> 5 -> 6
    l2.insertNode(2);
    l2.insertNode(5);
    l2.insertNode(6);

    Node *ans = solve(l1.head, l2.head, helper);

    helper.printList(ans);

    return 0;
}
