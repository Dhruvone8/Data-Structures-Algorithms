// Leetcode Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

int maxDepth(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }

    int leftH = maxDepth(root->left);
    int rightH = maxDepth(root->right);

    return 1 + max(leftH, rightH);
}

int main()
{
    // Creating the tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Maximum Depth: " << maxDepth(root) << endl;

    return 0;
}