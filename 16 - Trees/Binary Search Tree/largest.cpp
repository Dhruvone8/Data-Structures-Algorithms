// GFG Link: https://www.geeksforgeeks.org/problems/largest-bst/1

#include <bits/stdc++.h>
using namespace std;

class NodeValue
{
public:
    int maxNode;
    int minNode;
    int maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

NodeValue largestBSTHelper(Node *root)
{
    // An empty tree is a BST of size 0
    if (root == nullptr)
        return NodeValue(INT32_MAX, INT32_MIN, 0);

    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);

    // If current Node is greater than max in the left and smaller than min in the right
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        // Valid BST
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    return NodeValue(INT32_MIN, INT32_MAX, max(left.maxSize, right.maxSize));
}

int largestBst(Node *root)
{
    return largestBSTHelper(root).maxSize;
}
