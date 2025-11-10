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
    // Helper to build BST from sorted array
    Node *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return NULL;
        }

        int mid = (left + right) / 2;
        Node *root = new Node(nums[mid]);

        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }

    Node *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    void preOrder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main()
{
    BinaryTree tree;
    vector<int> nums = {-10, -3, 0, 5, 9};

    Node *root = tree.sortedArrayToBST(nums);
    cout << "Preorder of Balanced BST : ";
    tree.preOrder(root);
    cout << endl;
}
