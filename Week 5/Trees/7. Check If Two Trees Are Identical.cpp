#include <bits/stdc++.h>
using namespace std;

/// Node structure for binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree
{
public:
    // Check if two trees are identical
    bool isIdentical(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (!root1 || !root2)
        {
            return false;
        }
        if (root1->data == root2->data)
        {
            return isIdentical(root1->left, root2->left) &&
                   isIdentical(root1->right, root2->right);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    BinaryTree tree;

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    cout << "Are Trees Identical? " << (tree.isIdentical(root1, root2) ? "Yes" : "No") << endl;
}
