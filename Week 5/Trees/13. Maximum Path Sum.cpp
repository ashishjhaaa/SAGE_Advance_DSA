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
    // Helper function for maximum path sum
    int helperMaxPath(Node *root, int &maxSum)
    {
        if (root == NULL)
        {
            return 0;
        }

        // Compute left and right gain; ignore negatives using max(0, ...)
        int leftGain = max(0, helperMaxPath(root->left, maxSum));
        int rightGain = max(0, helperMaxPath(root->right, maxSum));

        // Compute current path sum including both sides
        int currentPath = root->data + leftGain + rightGain;

        // Update global maximum if needed
        maxSum = max(maxSum, currentPath);

        // Return max gain including this node to parent
        return root->data + max(leftGain, rightGain);
    }

    int maxPathSum(Node *root)
    {
        int maxSum = INT_MIN; // (Comment: changed from 0 to INT_MIN for all-negative trees)
        helperMaxPath(root, maxSum);
        return maxSum;
    }
};

int main()
{
    BinaryTree tree;
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum : " << tree.maxPathSum(root) << endl;
}
