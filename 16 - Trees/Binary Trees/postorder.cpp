// Leetcode Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

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

// Recursive Approach
void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}
