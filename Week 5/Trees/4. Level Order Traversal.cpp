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
    // Level Order Traversal (BFS)
    void levelOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            // Print each level in one line
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                cout << curr->data << " ";

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
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

    cout << "Level Order Traversal : ";
    tree.levelOrder(root);
    cout << endl;
}
