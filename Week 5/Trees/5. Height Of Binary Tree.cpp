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
    // Height (Depth) of Binary Tree
    int height(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
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

    cout << "Height of the Tree : " << tree.height(root) << endl;
}
