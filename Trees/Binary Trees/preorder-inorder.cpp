// Leetcode Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                          vector<int> &inorder, int inStart, int inEnd,
                          unordered_map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->val];

    // Number of nodes at the left
    int numsLeft = inRoot - inStart;

    // Left Subtree
    root->left = buildTreeHelper(preorder, preStart + 1, numsLeft + preStart, inorder, inStart, inRoot - 1, inMap);

    // Right Subtree
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;
    int n1 = preorder.size();
    int n2 = inorder.size();

    // Store inorder elements in a hashmap
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    TreeNode *root = buildTreeHelper(preorder, 0, n1 - 1, inorder, 0, n2 - 1, inMap);

    return root;
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTree(preorder, inorder);
    cout << root->val;

    return 0;
}