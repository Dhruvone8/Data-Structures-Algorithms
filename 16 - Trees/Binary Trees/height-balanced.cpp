// Leetcode Link: https://leetcode.com/problems/balanced-binary-tree/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default Constructor
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with only data
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with data and left, right nodes
    TreeNode(int data, TreeNode *leftNode, TreeNode *rightNode)
    {
        val = data;
        left = leftNode;
        right = rightNode;
    }
};

// A binary tree is height balanced if and only if for each node, the height difference between its left and right subtree is at most 1

// Find the height of the binary tree if its balanced, else return -1
int check(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftH = check(root->left);
    int rightH = check(root->right);

    if (leftH == -1 || rightH == -1)
    {
        return -1;
    }

    if (abs(leftH - rightH) > 1)
    {
        return -1;
    }

    return 1 + max(leftH, rightH);
}

bool isBalanced(TreeNode *root)
{
    int h = check(root);

    return h != -1;
}