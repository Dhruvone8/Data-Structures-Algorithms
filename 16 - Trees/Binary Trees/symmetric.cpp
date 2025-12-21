// Leetcode Link: https://leetcode.com/problems/symmetric-tree/description/

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

// Do a inorder traversal (root -> left -> right) on the left subtree
// Do (root -> right -> left) travsersal on the right subtree 
// Perform both the traversals simultaneously

bool symmetricHelper(TreeNode* left, TreeNode* right)
{
    // Return true if root of both left side and right side is null
    if(left == nullptr || right == nullptr)
    {
        return left == right;
    }

    if(left->val != right->val)
    {
        return false;
    }

    return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) 
{
    return (root == nullptr) || symmetricHelper(root->left, root->right);
}