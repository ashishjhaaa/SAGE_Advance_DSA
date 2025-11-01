#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

// utility: find length of list
int getLength(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

// main logic: find intersection node
Node *getIntersection(Node *head1, Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // move longer list's pointer forward by difference
    int diff = abs(len1 - len2);
    if (len1 > len2)
    {
        while (diff--)
            head1 = head1->next;
    }
    else
    {
        while (diff--)
            head2 = head2->next;
    }

    // move both until they meet
    while (head1 && head2)
    {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main()
{
    int n1, n2, val;

    cout << "Enter number of nodes in List1: ";
    cin >> n1;
    Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        Node *node = new Node(val);
        if (!head1)
            head1 = tail1 = node;
        else
        {
            tail1->next = node;
            tail1 = node;
        }
    }

    cout << "Enter number of nodes in List2: ";
    cin >> n2;
    Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        Node *node = new Node(val);
        if (!head2)
            head2 = tail2 = node;
        else
        {
            tail2->next = node;
            tail2 = node;
        }
    }

    // Create intersection manually for testing
    // Example: tail2->next = head1->next->next;

    Node *intersect = getIntersection(head1, head2);

    if (intersect)
        cout << "Intersection at node with value: " << intersect->data << endl;
    else
        cout << "No intersection found\n";

    return 0;
}
