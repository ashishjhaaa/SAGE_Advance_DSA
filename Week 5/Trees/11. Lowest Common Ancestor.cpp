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
    // Lowest Common Ancestor (for BST)
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        int curr = root->data;

        // Both nodes lie in the right subtree
        if (curr < p->data && curr < q->data)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Both nodes lie in the left subtree
        if (curr > p->data && curr > q->data)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Otherwise, current node is LCA
        return root;
    }
};

int main()
{
    BinaryTree tree;

    // BST structure
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node *p = root->left;        // Node 2
    Node *q = root->left->right; // Node 4

    Node *lca = tree.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor : " << lca->data << endl;
}
