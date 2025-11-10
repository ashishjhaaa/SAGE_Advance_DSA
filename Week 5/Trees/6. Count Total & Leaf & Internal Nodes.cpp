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
    // Count Total Nodes
    int countNodes(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Count Leaf Nodes
    int countLeafNodes(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }

    // Count Internal Nodes (Non-leaf nodes)
    int countInternalNodes(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
};

int main()
{
    BinaryTree tree;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Total Nodes : " << tree.countNodes(root) << endl;
    cout << "Leaf Nodes : " << tree.countLeafNodes(root) << endl;
    cout << "Internal Nodes : " << tree.countInternalNodes(root) << endl;
}
