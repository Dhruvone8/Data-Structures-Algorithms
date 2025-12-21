// Leetcode Link: https://leetcode.com/problems/count-complete-tree-nodes/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

int findLeftHeight(TreeNode* root)
{
    int height = 0;
    while(root != nullptr)
    {
        height++;
        root = root->left;
    }

    return height;
}

int findRighttHeight(TreeNode* root)
{
    int height = 0;
    while(root != nullptr)
    {
        height++;
        root = root->right;
    }

    return height;
}

int countNodes(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }

    int lefth = findLeftHeight(root->left);
    int righth = findRighttHeight(root->right);

    if(lefth == righth)
    {
        return (1 << (lefth + 1)) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}