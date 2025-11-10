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
    // Helper to check BST validity
    bool BSThelper(Node *root, int minVal, int maxVal)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data <= minVal || root->data >= maxVal)
        {
            return false;
        }
        return BSThelper(root->left, minVal, root->data) &&
               BSThelper(root->right, root->data, maxVal);
    }

    // Validate if given tree is BST
    bool isBST(Node *root)
    {
        return BSThelper(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    BinaryTree tree;

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Is Binary Tree a BST? " << (tree.isBST(root) ? "Yes" : "No") << endl;
}
