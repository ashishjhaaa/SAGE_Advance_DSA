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
    vector<vector<int>> verticalOrder(Node *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }

        map<int, vector<int>> nodes; // column -> nodes
        queue<pair<Node *, int>> q;  // node, column
        q.push({root, 0});

        while (!q.empty())
        {
            Node* node = q.front().first;
            int col = q.front().second;
            q.pop();

            nodes[col].push_back(node->data);

            if (node->left)
                q.push({node->left, col - 1});
            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto &pair : nodes)
        {
            res.push_back(pair.second);
        }
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

    vector<vector<int>> res = tree.verticalOrder(root);

    cout << "Vertical Order Traversal : " << endl;
    for (auto &col : res)
    {
        for (int val : col)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}