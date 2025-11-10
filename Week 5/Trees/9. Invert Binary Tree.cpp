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
    // Invert (Mirror) the Binary Tree
    Node *invertTree(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        Node *temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }

    // Simple Inorder traversal for validation
    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
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

    cout << "Original Tree (Inorder) : ";
    tree.inOrder(root);
    cout << endl;

    root = tree.invertTree(root);

    cout << "Inverted Tree (Inorder) : ";
    tree.inOrder(root);
    cout << endl;
}
