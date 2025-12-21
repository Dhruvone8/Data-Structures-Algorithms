// Leetcode Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

int Pathsum(TreeNode *root, int &maxsum)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftsum = max(0, Pathsum(root->left, maxsum));
    int rightsum = max(0, Pathsum(root->right, maxsum));

    maxsum = max(maxsum, (leftsum + rightsum + root->val));
    return root->val + max(leftsum, rightsum);
}

int maxPathSum(TreeNode *root)
{
    int maxsum = root->val;
    Pathsum(root, maxsum);
    return maxsum;
}