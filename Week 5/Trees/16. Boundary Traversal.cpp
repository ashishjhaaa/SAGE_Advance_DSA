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
    void printLeftBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (curr->left || curr->right)
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void printLeaves(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            res.push_back(root->data);
        printLeaves(root->left, res);
        printLeaves(root->right, res);
    }

    void printRightBoundary(Node *root, vector<int> &res)
    {
        vector<int> temp;
        Node *curr = root->right;
        while (curr)
        {
            if (curr->left || curr->right)
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;

        res.push_back(root->data);
        printLeftBoundary(root, res);
        printLeaves(root, res);
        printRightBoundary(root, res);
        return res;
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> res = tree.boundaryTraversal(root);
    cout << "Boundary Traversal : ";
    for (int val : res)
        cout << val << " ";
    cout << endl;
}
