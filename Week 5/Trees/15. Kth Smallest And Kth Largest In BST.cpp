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
    // Inorder traversal (ascending order for BST)
    void helperInorder(Node *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }
        helperInorder(root->left, arr);
        arr.push_back(root->data);
        helperInorder(root->right, arr);
    }

    int kthSmallestNumber(Node *root, int k)
    {
        vector<int> arr;
        helperInorder(root, arr);
        return arr[k - 1];
    }

    int kthLargestNumber(Node *root, int k)
    {
        vector<int> arr;
        helperInorder(root, arr);
        return arr[arr.size() - k];
    }

    // Optimal approach without extra array (inorder count)
    void inorderHelper(Node *root, int &k, int &ans)
    {
        if (root == NULL)
            return;
        inorderHelper(root->left, k, ans);
        k--;
        if (k == 0)
        {
            ans = root->data;
            return;
        }
        inorderHelper(root->right, k, ans);
    }

    int kthSmallerNumberOptimal(Node *root, int k)
    {
        int ans = -1;
        inorderHelper(root, k, ans);
        return ans;
    }

    void inorderHelperForKthLargest(Node *root, int &k, int &ans)
    {
        if (root == NULL)
            return;
        inorderHelperForKthLargest(root->right, k, ans);
        k--;
        if (k == 0)
        {
            ans = root->data;
            return;
        }
        inorderHelperForKthLargest(root->left, k, ans);
    }

    int kthLargestNumberOptimal(Node *root, int k)
    {
        int ans = -1;
        inorderHelperForKthLargest(root, k, ans);
        return ans;
    }
};

int main()
{
    BinaryTree tree;

    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Kth Smallest : " << tree.kthSmallerNumberOptimal(root, 3) << endl;
    cout << "Kth Largest : " << tree.kthLargestNumberOptimal(root, 2) << endl;
}
