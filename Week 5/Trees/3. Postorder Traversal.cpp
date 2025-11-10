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
    // Postorder Traversal -> L -> R -> Root
    void postOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
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

    cout << "Postorder Traversal : ";
    tree.postOrder(root);
    cout << endl;
}
