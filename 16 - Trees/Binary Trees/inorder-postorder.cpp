// Leetcode Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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

TreeNode *buildTreehHelper(vector<int> &inorder, int inStart, int inEnd,
                           vector<int> &postorder, int pStart, int pEnd,
                           unordered_map<int, int> &inMap)

{
    if(pStart > pEnd || inStart > inEnd)
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(postorder[pEnd]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    // Left Subtree
    root->left = buildTreehHelper(inorder, inStart, inRoot - 1, postorder, pStart, pStart + numsLeft - 1, inMap);

    // right subtree
    root->right = buildTreehHelper(inorder, inRoot + 1, inEnd, postorder, pStart + numsLeft, pEnd - 1, inMap);

    return root;

}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inMap;
    int n = inorder.size();

    for(int i = 0; i < n; i++)
    {
        inMap[inorder[i]] = i;
    }

    TreeNode* root = buildTreehHelper(inorder, 0, n - 1, postorder, 0, n - 1, inMap);

    return root;
}