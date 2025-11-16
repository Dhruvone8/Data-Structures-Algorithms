// Leetcode Link: https://leetcode.com/problems/diameter-of-binary-tree/

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

// Diameter is the longest path between any 2 nodes

int maxdiameter(TreeNode *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lefth = maxdiameter(root->left, diameter);
    int righth = maxdiameter(root->right, diameter);

    diameter = max(diameter, lefth + righth);

    return 1 + max(lefth, righth);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    maxdiameter(root, diameter);
    return diameter;
}