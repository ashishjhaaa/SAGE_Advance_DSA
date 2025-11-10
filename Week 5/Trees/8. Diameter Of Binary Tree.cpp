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
    // Diameter of Binary Tree (Longest path between any two nodes)
    int diameter(Node *root, int &maxDiameter)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = diameter(root->left, maxDiameter);
        int rightHeight = diameter(root->right, maxDiameter);

        // Possible diameter passing through current node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight + 1);
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int maxDiameter = 0;
    tree.diameter(root, maxDiameter);
    cout << "Diameter of the Tree : " << maxDiameter << endl;
}
