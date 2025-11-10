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
    // Find path from root to a given node
    bool findPath(Node *root, int target, vector<int> &path)
    {
        if (root == NULL)
        {
            return false;
        }

        path.push_back(root->data);

        if (root->data == target)
        {
            return true;
        }

        if (findPath(root->left, target, path) || findPath(root->right, target, path))
        {
            return true;
        }

        // Backtrack if not found in this branch
        path.pop_back();
        return false;
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
    root->right->right = new Node(6);

    vector<int> path;
    int target = 5;

    if (tree.findPath(root, target, path))
    {
        cout << "Path from Root to Node " << target << " : ";
        for (int val : path)
            cout << val << " ";
        cout << endl;
    }
    else
    {
        cout << "Target not found in the tree.";
    }
}
